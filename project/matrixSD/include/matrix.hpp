/***********************************************
 *              DESCRIPTION                    *
 * File contains a definition of a class Matrix
 * in the namespace sd. The class implements the 
 * most general case of matrix - two dimensional
 * rectangle matrix - and apropriate methods.
 * It is a template class and because of it, it
 * has to contain all definitions in .hpp file
 * (prof. Cyganek 3.15.5).
 ***********************************************/

#pragma once

#include <type_traits> //is_arithmetic_v
#include <vector>
#include <iomanip>     //for better-looking output stream 

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
    * access to matrix's elements - matA [n][m].
    * Additionally std::vector watches over 
    * allocation of memory and realising memory
    * by deleting objects of  the class.
    * Note that first element of first row has
    * index metA [0][0]).
    ***********************************************/
    using TVector = std::vector<T>;         
    using TMatrix = std::vector<TVector>;

    size_t m_rows, m_columns;  // number of rows and columns in matrix
    TMatrix m_matrix;       // object containg matrix's data

    uint elementDisplayWidth = 6;  // default value for << operator

  public:

    /***********************************************
    *              CONSTRUCTORS                   *
    * No 1: Default constructor 
    * Create a scalar (1x1 matrix) with T-type 0 value.
    * Ex.:
    *    Matrix<double> matA;
    * Result:
    *     
    *   matA = [ 0.0 ]
    *          
    * No 2: Intializing a matrix with a given value
    * and by giving a numer of rows and colums.
    * Ex.:
    *    Matrix matA(3, 2, 1);
    * or better (with explicit type specification)
          Matrix<int> matA(3, 2, 1);
    * Result:
    *          [ 1 1 ]
    *   matA = | 1 1 |
    *          [ 1 1 ]
    * Note: the dimensions argument are int, because
    * by giving a negative value it will be convert to
    * very large size_t value and programm will try to
    * alocate a big amount of memory - what propably
    * will cause a termination of programm.  
    ***********************************************/

    Matrix( int rows = 1, int columns = 1, T value = T{} ){
      // Validation:
      if ( (rows <= 0) || (columns <= 0) ){
        throw std::invalid_argument( "Matrix dimensions have to be greater than 0! ");
      }

      m_rows = static_cast<size_t>(rows);   // setting the values and explicit type converion
      m_columns = static_cast<size_t>(columns);  
      m_matrix = TMatrix( m_rows, TVector(m_columns, value) ); // creating a matrix 
    }

    /***********************************************
    *               GETTERS                       *
    * No 1: Getting value of element given 
    * by row and culuumn indexes.
    * Ex.:
    *  Let's assume existance of object:
    *          [ 1 2 ]
    *   matA = | 3 4 |
    *          [ 5 6 ]
    *  Executiong code:
    *    matA.getValue(2, 1);
    *  will rerurn T-type value (int):
    *    6
    ***********************************************/

    T getValue( size_t row, size_t column ) const {
      //Validation (if given index is negative it will be 
      //converted to a very large value)
      if ( (row >= m_rows) || (column >= m_columns) ){
        throw std::out_of_range( "Out of range!" );
      }
      return m_matrix[row][column];      
    }
    /***********************************************
    * No 2: Getting whole row.
    * Ex.:
    *  Let's assume existance of object:
    *          [ 1 2 ]
    *   matA = | 3 4 |
    *          [ 5 6 ]
    *  Executiong code:
    *    matA.getRow(1);
    *  will return T-type vector (int):
    *  {3, 4}
    ***********************************************/
    TVector getRow( size_t row ) const {
      if ( row >= m_rows ){
        throw std::out_of_range( "Out of range!" );  
      }
      return m_matrix[row];
    }
    /***********************************************
    * No 3: Getting whole column.
    * Ex.:
    *  Let's assume existance of object:
    *          [ 1 2 ]
    *   matA = | 3 4 |
    *          [ 5 6 ]
    *  Executiong code:
    *    matA.getColumn(1);
    *  will return T-type vector (int):
    *  {2, 4, 6}
    ***********************************************/
    TVector getColumn( size_t column ) const {
      if ( column >= m_columns ){
        throw std::out_of_range( "Out of range!" );  
      }
      TVector temp {};    // creating an empty TVector
      for ( size_t row = 0; row < m_rows; row++ ){
        temp.push_back( m_matrix[row][column] ); //filling it with values
      }
      return temp;  
    }

    /***********************************************
    *         Getting matrix dimensions           *
    *  Fuction returns a 2-elements vector containing
    * number of rows and columns of matrix.
    ***********************************************/
    std::vector<size_t> getDimensions() const {
      return std::vector<size_t> { m_rows, m_columns };
    }

    size_t getRowDim() const {
      return m_rows;
    }
    size_t getColumnDim() const {
      return m_columns;
    }
    /***********************************************
    *               SETTERS                       *
    * No 1: Setting value of element given 
    * by row and culuumn indexes.
    * Ex.:
    *  Let's assume existance of object:
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 6.0 ]
    *  Executiong code:
    *    matA.setValue(2, 1, 5.7);
    *  will result in new values of 
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 5.7 ]
    ***********************************************/

    void setValue( size_t row, size_t column, T value ){
      //Validation
      if ( (row >= m_rows) || (column >= m_columns) ){
        throw std::out_of_range( "Out of range!" );
      }
      m_matrix[row][column] = value;
    }

    /***********************************************
    * No 2: Setting whole row.
    * Ex.:
    *  Let's assume existance of object:
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 6.0 ]
    *  Executiong code:
    *    std::vector<double> v1{1.1, 2.2};
    *    matA.setRow(1, v1);
    *  will result in new values of 
    *          [ 1.0 2.0 ]
    *   matA = | 1.1 2.2 |
    *          [ 5.0 5.7 ]
    ***********************************************/
    void setRow( size_t row, TVector vector ){
      if ( row >= m_rows ){
        throw std::out_of_range( "Out of range!" );  
      }
      if ( vector.size() != m_columns ){
        throw std::invalid_argument( "Rows dimensions missmatch!" );
      }

      /***********************************************
      * Using std::swap make that values from 
      * m_matrix [row] will be replaced with that 
      * from vector and vice versa.
      * It fulfills setter's function as vector 
      * disappears in next step.
      ***********************************************/
      std::swap(m_matrix [row], vector); 
    }

    /***********************************************
    * No 3: Setting whole column.
    * Ex.:
    *  Let's assume existance of object:
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 6.0 ]
    *  Executiong code:
    *    std::vector<double> v1{1.1, 2.2, 3.3};
    *    matA.setColumn(0, v1);
    *  will result in new values of 
    *          [ 1.1 2.0 ]
    *   matA = | 2.2 4.0 |
    *          [ 3.3 6.0 ]
    ***********************************************/
  
    void setColumn( size_t column, TVector vector ){
      if ( column >= m_columns ){
        throw std::out_of_range( "Out of range!" );  
      }
      if ( vector.size() != m_rows ){
        throw std::invalid_argument( "Columns dimensions missmatch!" );
      }
      for ( size_t row = 0; row < m_rows; row++ ){
        m_matrix[row][column] = vector[row];
      }
    }

    /***********************************************
    *      Setting display width of elements      *
    * It provides better-looking and configurable
    * display option for matrix using << operator.
    * User can set with it how wide each element is.
    * That provides alignment of elements.
    * Default value is 6.
    ***********************************************/  
    void setElementDisplayWidth( int value ){
      if ( value <= 0 ){
        throw std::invalid_argument( "Display width has to be bigger than 0!" );
      }
      elementDisplayWidth = static_cast<uint>(value);
    }
    /***********************************************
    *            Matrix operations                *
    * In comments there will be given short examples
    * of each operation and mathematical assumptions
    * which have to be fulfilled.
    ***********************************************/
    /***********************************************
    *            Matrix transposition              *
    *              matA.transpose()
    * Any matrix can be transposed. If matA is m x n
    * matrix than matA_trasposed is n x m matrix such
    * that [matA_trasposed]_{ij} = [matA]{ji}
    ***********************************************/
    Matrix transpose() const {
      Matrix result( m_columns, m_rows, T{0} ); 
      for ( size_t row = 0; row < result.m_rows; row++ ){
        for ( size_t column = 0; column < result.m_columns; column++ ){
          result.m_matrix[row][column] = m_matrix[column][row];
        }
      }
      return result; 
    }
    /***********************************************
    *                 Operators                   *
    * In comments there will be given short examples
    * of each operation and mathematical assumptions
    * which have to be fulfilled.
    ***********************************************/
    /***********************************************
    *                operator +                   *
    *            matC = matA + matB               *
    * Mathematical assumptions:
    *   1) dim(matA) = dim(matB)
    * Description of operation:
    * Elements of both martixess with the same 
    * indices are added.
    * Ex.:
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 6.0 ]
    *
    *          [ 6.1 5.2 ]
    *   matB = | 4.3 3.4 |
    *          [ 2.5 1.6 ]
    *
    *          [ 7.1 7.2 ]
    *   matC = | 7.3 7.4 |
    *          [ 7.5 7.6 ]
    ***********************************************/    
    
    // Matrix<T> operator + ( const Matrix & other ) const {
    //   if ( (m_rows != other.getRowDim()) || (m_columns != other.getColumnDim() ) ){
    //     throw std::invalid_argument( "Matrixes dimensions error!" );
    //   }
      
    //   Matrix result( m_rows, m_columns, T{0} );
    //   for ( size_t row = 0; row < m_rows; row++ ){
    //     for ( size_t column = 0; column < m_columns; column++ ){
    //       result.m_matrix[row][column] = m_matrix[row][column] + other.m_matrix[row][column];
    //     }
    //   }
    //   return result;  
    // }

    template <typename T2>
    requires std::is_arithmetic_v<T2>  
    Matrix<T> operator + ( const Matrix<T2> & other ) const {
      if ( (m_rows != other.getRowDim()) || (m_columns != other.getColumnDim() ) ){
        throw std::invalid_argument( "Matrixes dimensions error!" );
      }
      
      Matrix<T> result( m_rows, m_columns, T{0} );
      for ( size_t row = 0; row < m_rows; row++ ){
        for ( size_t column = 0; column < m_columns; column++ ){
          result.m_matrix[row][column] = m_matrix[row][column] + static_cast<T>( other( row,column ) );
        }
      }
      return result;  
    }


    /***********************************************
    *                operator +=                   *
    *               matA += matB                   *
    * Mathematical assumptions:
    *   1) dim(matA) = dim(matB)
    * Description of operation:
    * Elements of both martixess with the same 
    * indices are added.
    * Ex.:
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 6.0 ]
    *
    *          [ 6.1 5.2 ]
    *   matB = | 4.3 3.4 |
    *          [ 2.5 1.6 ]
    *
    *          matA += matB;  
    *
    *          [ 7.1 7.2 ]
    *   matA = | 7.3 7.4 |
    *          [ 7.5 7.6 ]
    ***********************************************/  

    Matrix & operator += ( const Matrix & other ){
      if ( (m_rows != other.m_rows) || (m_columns != other.m_columns) ){
      throw std::invalid_argument( "Matrixes dimensions error!" );
      }
      for ( size_t row = 0; row < m_rows; row++ ){
        for ( size_t column = 0; column < m_columns; column++ ){
          m_matrix[row][column] += other.m_matrix[row][column];
        }
      }
      return *this;  
    }

   /***********************************************
    *                operator -                   *
    *            matC = matB - matA               *
    * Mathematical assumptions:
    *   1) dim(matA) = dim(matB)
    * Description of operation:
    * Elements of both martixess with the same 
    * indices are substracted. 
    * Ex.:
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 6.0 ]
    *
    *          [ 6.1 5.2 ]
    *   matB = | 4.3 3.4 |
    *          [ 2.5 1.6 ]
    *
    *          [ 5.1  3.2 ]
    *   matC = | 1.3 -1.4 |
    *          [-2.5 -5.6 ]
    ***********************************************/    

    Matrix operator - ( const Matrix & other ) const {
      if ( (m_rows != other.m_rows) || (m_columns != other.m_columns) ){
        throw std::invalid_argument( "Matrixes dimensions error!" );
      }
      Matrix result( m_rows, m_columns, T{0} );
      for ( size_t row = 0; row < m_rows; row++ ){
        for ( size_t column = 0; column < m_columns; column++ ){
          result.m_matrix[row][column] = m_matrix[row][column] - other.m_matrix[row][column];
        }
      }
      return result;  
    }

    /***********************************************
    *                operator -=                   *
    *               matA -= matB                   *
    * Mathematical assumptions:
    *   1) dim(matA) = dim(matB)
    * Description of operation:
    * Elements of both martixess with the same 
    * indices are substracted. 
    * Ex.:
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 6.0 ]
    *
    *          [ 6.1 5.2 ]
    *   matB = | 4.3 3.4 |
    *          [ 2.5 1.6 ]
    *
    *          matA -= matB;  
    *
    *          [ 5.1  3.2 ]
    *   matA = | 1.3 -1.4 |
    *          [-2.5 -5.6 ]
    ***********************************************/  

    Matrix & operator -= ( const Matrix & other ) {
      if ( (m_rows != other.m_rows) || (m_columns != other.m_columns) ){
      throw std::invalid_argument(" Matrixes dimensions error!" );
      }
      
      for ( size_t row = 0; row < m_rows; row++ ){
        for ( size_t column = 0; column < m_columns; column++ ){
          m_matrix[row][column] -= other.m_matrix[row][column];
        }
      }
      return *this;  
    }

    /***********************************************
    *                operator *                   *
    *           matC = matA * matB                *
    * Mathematical assumptions:
    *   1) Dimensions:
    *      matA is an m x n matrix
            matB is an n x p matrix
    * Description of operation:
    *      matC is an m x p matrix such that
    *      c_ij = sum_{k=1}^n a_ik*b_kj
    *      for i = 1, ... , m
    *          j = 1, ... , p
    * Ex.:
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 6.0 ]
    *
    *          [ 1.1 1.2  1.3]
    *   matB = [ 2.1 2.2  2.3]
    *          
    *
    *          matC = matA * matB;  
    *
    *          [ 5.3   5.6   5.9 ]
    *   matC = | 11.7  12.4  13.1|
    *          [ 18.1  19.2  20.3]
    ***********************************************/  
    Matrix operator*( const Matrix & other ) const {
      if ( m_columns != other.m_rows ){
        throw std::invalid_argument(" Matrixes dimensions error! ");
      }
      Matrix result( m_rows, other.m_columns, T{0} );
      for ( size_t row = 0; row < m_rows; row++ ){
        for ( size_t column = 0; column < other.m_columns; column++ ){
          for ( size_t k = 0; k < m_columns; k++ ){
            result.m_matrix[row][column] += m_matrix[row][k]*other.m_matrix[k][column];
          }
        }
      }
      return result;  
    }

    /***********************************************
    *                operator *                   *
    *           matC = matA * scalar              *
    *           matC = scalar * matA              *
    * No mathematical assumptions:
    * Description of operation:
    *    matC is a matrix where every element is
    *    product of matA elements with scalar           
    * Operation is (unlike matrix multiplication) 
    * commutitative and scalar can be of any arithmetic
    * type (it will be convertet into type of matrix).
    * Ex.:
    *          [ 1.0 2.0 ]
    *   matA = | 3.0 4.0 |
    *          [ 5.0 6.0 ]
    *
    *   scalar = 2.0;
    *          
    *          matC = scalar * matA;  
    *
    *          [ 2.0   4.0 ]
    *   matC = | 6.0   8.0 |
    *          [ 10.0  12.0]
    ***********************************************/
    template <typename S>
    requires std::is_arithmetic_v<S>  
    Matrix operator * ( const S scalar ) const {
      Matrix result( m_rows, m_columns, T{0} );
      for ( size_t row = 0; row < m_rows; row++ ){
        for ( size_t column = 0; column < m_columns; column++ ){
          result.m_matrix[row][column] = m_matrix[row][column] * static_cast<T>(scalar) ;
        }
      }
      return result;  
    }

    template <typename S>
    requires std::is_arithmetic_v<S>  
    friend Matrix operator * ( const S scalar, const Matrix & matrix ){
      return matrix * scalar;
    }

    /***********************************************
    *                operator *=                   *
    * For matrix multiplication this operator has 
    * sense only for square matrix due to 
    * dimmensions restrictions. It has thou sense for
    * scalar multiplication.       
    ***********************************************/  
    template <typename S>
    requires std::is_arithmetic_v<S>  
    Matrix & operator *= ( const S scalar ) {
      for ( auto & row : m_matrix ){
        for ( auto & element : row ){
          element *= static_cast<T>(scalar) ;
        }
      }
      return *this;  
    }

    /***********************************************
    *                operator ()                   *
    *                matA(r,c)
    * Operator () allows to get elements value
    * with indices r and c.
    * It is acually same as function getValue(r,c)       
    ***********************************************/  

    T operator () ( const int r, const int c ){
      return getValue( r, c );
    }

    /***********************************************
    *                operator <<                   *
    *                
    * Operator << allows to send a matrix to ostream
    * It cooperates with cout: it make always new line
    * before and after displaing matrix. To provide
    * good-looking display the user should change 
    * column width with setElementDisplayWidth function
    * (default value = 6 + " ").      
    ***********************************************/  
    
    friend std::ostream& operator<<( std::ostream& os, const Matrix& matrix ){
      os << "\n"; // always begins from new line
      for ( auto const & row : matrix.m_matrix ){   
        for (auto const & element : row){
          os << std::setw(matrix.elementDisplayWidth) << element << " ";
        } 
        os << "\n";
      }

      return os;
    }
  };
      


} // namespace sd

