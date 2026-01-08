/***********************************************
 *              DESCRIPTION                    *
 * File contains a definition of a class 
 * SquareMatrix in the namespace sd, which is inherent
 * class of Matrix. The class implements the 
 * two dimensional square matrix.
 ***********************************************/

#pragma once

#include "matrix.hpp"


namespace sd{

  constexpr double eps = 1e-12;   // near 0.0 definition

  template <typename T>
  requires std::is_arithmetic_v<T>
  class SquareMatrix : public Matrix<T> {
  private:
    // using Matrix<T>::m_rows;      // irt brings base-class members into scope
    // using Matrix<T>::m_columns;   
     using Matrix<T>::m_matrix;    

  protected:
    size_t m_dim;
  public:
    /***********************************************
    *              CONSTRUCTORS                   *
    * No 1: Default constructor 
    * Create a scalar (1x1 matrix) with T-type 0 value.
    * Ex.:
    *    SquareMatrix<double> matA;
    * Result:
    *     
    *   matA = [ 0.0 ]
    *          
    * No 2: Intializing a matrix with a given value
    * and dimension.
    * Ex.:
    *    SquareMatrix matA(3, 1);
    * or better (with explicit type specification)
          SquareMatrix<int> matA(3, 1);
    * Result:
    *          [ 1 1 1 ]
    *   matA = | 1 1 1 |
    *          [ 1 1 1 ]
    * Note: the dimensions argument are int, because
    * by giving a negative value it will be convert to
    * very large size_t value and programm will try to
    * alocate a big amount of memory - what propably
    * will cause a termination of programm.  
    * No 3: Copy constructor is the default one - it 
    * need no implementation.
    ***********************************************/

    SquareMatrix( int dim = 1, T value = T{} ) 
      : Matrix<T>( dim, dim, value), m_dim( dim ) {}

    SquareMatrix( Matrix<T> matrix) : Matrix<T>( matrix ), m_dim( matrix.getRowDim() ) {

      if ( matrix.getRowDim() != matrix.getColumnDim() ){
        throw std::invalid_argument( "Dimension error!" );
      }
    
    }
    
    /***********************************************
    *            Matrix operations                *
    * In comments there will be given short examples
    * of each operation and mathematical assumptions
    * which have to be fulfilled.
    ***********************************************/

    /***********************************************
    *                   Minor                      *
    *                matA.minor( r, c )
    * If A is n x n matix, then its minor is an
    * n-1 x n-1 matrix developed from A by deleting
    * r-th row and c-th column.
    * Ex.:
    *          [ 1 2 3 ]
    *   matA = | 4 5 6 |
    *          [ 7 8 9 ]
    * 
    * 
    *                    [ 1 2 ]
    *   matA.min(1, 2) = [ 7 8 ]
    *                    
    ***********************************************/

    SquareMatrix minor( size_t row, size_t column ) const {

      if ( (row >= m_dim) || (column >= m_dim) ){
        throw std::out_of_range( "Out of range!" );
      }

      SquareMatrix result( m_dim - 1 ); 

      size_t rr = 0;    //result matrix row index
      for( size_t r = 0; r < m_dim; r++ ){
        
        if (r == row){
            continue;     //skip given row
        }
        
        size_t cc = 0;  //result matrix column index
        for( size_t c =0; c < m_dim; c++ ){

          if (c == column){
            continue;     //skip given column
          }

          result( rr, cc ) = (*this)( r, c );
          cc++;     //increment column index
        }

        rr++;     //increment row index
      } 

      return result;
    }

    /***********************************************
    *                 Determinant                  *
    *                  matA.det()
    * If A is n x n matix, then determinant can be 
    * given as:
    * det(A) = sum_{j=0}^{n-1} (-1)^j*a_{0j}*det(Minor_{0j}) 
    * Note: Determinant can be calculated in relation to 
    * any row or column. Here it will be always done 
    * with row 0.
    * Given algorith is non effective for big matrixes. 
    ***********************************************/
    
    T det() const {
      
      //special cases for dim = 1 and dim = 2:
      if ( m_dim == 1 ) {
        return (*this)( 0, 0 );  
      }

      if (m_dim == 2) {
        return (*this)( 0, 0 ) * (*this)( 1, 1 )
              -(*this)( 0, 1 ) * (*this)( 1, 0 );
      }

      T result {};

      for ( size_t column = 0; column < m_dim; column++ ){
        
        T sign =  ( column % 2 == 0 ) ? T{1} : T{-1}; //even with +, odd with -
        SquareMatrix minorMat = minor( 0, column );
        result += sign * (*this)( 0, column ) * minorMat.det();
      }

      return result;
    }

    /***********************************************
    *             Cofactor Matrix               *
    *                matA.cofactor()
    * Cofactor Matrix of n x n Matrix is an n x n
    * Matrix build as follow:
    * 
    * C_{ij} = (-1)^(i+j) * det( Minor_{ij} )
    * 
    ***********************************************/

    SquareMatrix cofactor() const {

      SquareMatrix result( m_dim, T{0} );

      for (size_t row = 0; row < m_dim; row++ ){
        for (size_t column = 0; column < m_dim; column++ ){
          T sign =  ( (row + column ) % 2 == 0 ) ? T{1} : T{-1}; //even with +, odd with  
          result( row, column ) = sign * minor(row, column).det(); 
        }
      }

      return result;
    }

    /***********************************************
    *             Matrix inversion               *
    *                matA.inv()
    * Matrix B is inverse to matrix A, if 
    *     matA * matB = matB * matA = In 
    * whre In is n-dimensional identitty matrix.
    * Matrix B is often designated as (matA)^(-1).
    * It can be calculated as follows
    *   matB = 1/det(matA) * CT
    * where CT is trasposed cofactor matrix  
    * Assumption:
    *   1) Matrix has to be invertible, that is
    *      it's determinat has to be diferent than 0;
    * Note: inversed Matrix will generally has double
    * type even when original was intiger matrix. 
    ***********************************************/

    SquareMatrix<double> inverse(){
      
      T detA = det();
      
      if ( std::abs( detA ) <= eps ){
        throw std::invalid_argument( "Math error. Matrix is not invertible!" );
      }

      return (1.0 / detA) * ( cofactor().transpose() );

    }

  };    //class 



} //namespace