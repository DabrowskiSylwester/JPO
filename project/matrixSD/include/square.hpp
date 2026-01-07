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

  template <typename T>
  requires std::is_arithmetic_v<T>
  class SquareMatrix : public Matrix<T> {
  private:

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
    ***********************************************/
    SquareMatrix( int dim = 1, T value = T{} ) 
      : Matrix<T>( dim, dim, value) {}
    
    /***********************************************
    *            Matrix operations                *
    * In comments there will be given short examples
    * of each operation and mathematical assumptions
    * which have to be fulfilled.
    ***********************************************/
    /***********************************************
    *         Matrix LU decomposition              *
    * LU decomposition is widely used in mathematic
    * It consist of finding two triangular matrixes
    * L and U so that their multiplication L*U gives
    * original matrix.
    ***********************************************/
    SquareMatrix<T> toLowTriangular(){

    }

    /***********************************************
    *             Matrix determinant               *
    *                matA.det()
    * 
    ***********************************************/
  
  };    //class 



} //namespace