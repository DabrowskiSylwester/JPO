/***********************************************
 *              DESCRIPTION                    *
 * File contains a definition of a class Matrix
 * in the namespace sd. The class implements the 
 * most general case of matrix - two dimensional
 * rectangle matrix - and apropriate methods.
 * It is a template class and because of it, it
 * has to contain all definitions in .hpp file.
 ***********************************************/

#pragma once

#include <type_traits> //is_arithmetic_v
#include <vector>

namespace sd {


template <typename T>
requires std::is_arithmetic_v<T>
class Matrix {
private:
/***********************************************
 * Matrix is implemeted as a vector of T-type
 * vectors. It provides both all arithmetic 
 * types of data, which can be handeled by 
 * the class, and possibility of user friendly 
 * access to matrix's elements - matA(n, m).
 * Additionally std::vector watches over 
 * allocation of memory and realising memory
 * by deleting objects of  the class.
 ***********************************************/
    using TVector = std::vector<T>;         
    using TMatrix = std::vector<TVector>;

    int m_rows, m_columns;  // number of rows and columns in matrix
    TMatrix m_matrix;       // object containg matrix's data

public:

/***********************************************
 *              CONSTRUCTORS                   *
 * No 1: Intializing a matrix with a given value
 * and by giving a numer of rows and colums.
 * Ex.:
 *    sd::Matrix matA(3,2,1)
 * Result:
 *          [ 1 1 ]
 *   matA = | 1 1 |
 *          [ 1 1 ]
 ***********************************************/
    Matrix(int rows, int columns, T value) 
      : m_rows(rows), 
        m_columns(columns), 
        m_matrix(rows, TVector(columns, value)) {}
/***********************************************
 * No 2: Intializing a matrix by giving vectors
 * Ex.:
 *    sd::Matrix matA(
 *        {}
 *    )
 * Result:
 *          [ 1 1 ]
 *   matA = | 1 1 |
 *          [ 1 1 ]
 ***********************************************/
     





// operator <<
   
};
    

} // namespace sd

