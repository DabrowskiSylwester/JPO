#pragma once

#include "square.hpp"

namespace sd{

  enum class TriangleType { Lower, Upper }; // Matrix Types  

  template <typename T>
  requires std::is_arithmetic_v<T>
  class TriangularMatrix : public SquareMatrix<T> {
  private:

    using SquareMatrix<T>::m_dim;   

    TriangleType m_type;

    bool writePermission (size_t row, size_t column) const {
      return (( m_type == TriangleType::Lower ) && ( row >= column ))
          || (( m_type == TriangleType::Upper ) && ( row <= column ));
    }

  public:
      /***********************************************
    *              CONSTRUCTORS                   *
    * No 1: Default constructor 
    * Create a 1x1 matrix with T-type 0 value.
    * Ex.:
    *    TraiangularMatrix<double> matA;
    * Result:
    *     
    *   matA = [ 0.0 ]
    *          
    * No 2: Intializing a matrix with a given dimension, 
    * type and value.
    * .
    * Ex.:
    *    TriangularMatrix matA(3, TriangleType::Upper, 1);
    * or better (with explicit type specification)
         TriangularMatrix<int> matA(3, 1);
    * Result:
    *          [ 1 1 1 ]
    *   matA = | 0 1 1 |
    *          [ 0 0 1 ]
    * Note: the dimensions argument are int, because
    * by giving a negative value it will be convert to
    * very large size_t value and programm will try to
    * alocate a big amount of memory - what propably
    * will cause a termination of programm.  
    * No 3: Copy constructor is the default one - it 
    * need no implementation.
    ***********************************************/  
    TriangularMatrix( int dim = 1, TriangleType type = TriangleType::Lower, T value = T{0}) : SquareMatrix<T>( dim, T{0} ), m_type( type ) {
      
      for ( size_t row = 0; row < m_dim; row++ ){
        for ( size_t column = 0; column < m_dim; column ++ ){
          if ( writePermission( row, column ) ){
            SquareMatrix<T>::operator()( row, column ) = value;
          }
        }
      }
    }
    
    /***********************************************
    *               SETTERS                       *
    * Setter and operator() has to provide a controll to prevent 
    * writing in 'zero-pasrt' of matrix.
    * Read-version of operator() is the same as for 
    * other matrixes, but has to overriden.
    ***********************************************/

    T& operator () (size_t r, size_t c) { 
      
      if ( !writePermission( r, c ) ){
        throw std::domain_error( "Access denied to that index of triangular  matrix!");
      }
      
      return SquareMatrix<T>::operator()( r, c );  
    }

    T operator()(size_t r, size_t c) const {
      return SquareMatrix<T>::operator()(r, c);
    }

  };  //UTriangleMatrix


}  //namespace