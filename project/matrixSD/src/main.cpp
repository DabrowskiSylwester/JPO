#include <iostream>

#include "matrix.hpp"
#include "square.hpp"
#include "triangular.hpp"

using std::cout, std::cin, std::endl;

int main(){
    //constructors test:
    sd::Matrix<double> matA(3, 2, 1.0);
    sd::Matrix<double> matB(3, 2, 2.0);
    sd::Matrix<double> matC;
    try{
        sd::Matrix<double> matD(-3, 2, 1.0);
    }
    catch( std::invalid_argument & ex ){
        cout << ex.what() << endl;
    }

    //getters and setters test:
    cout << "*************************************" << endl;
    cout << "Setters and getters:" << endl;
    matA.setValue(1, 0, -3.6);
    cout << "Changed element: " << matA.getValue(1, 0) << endl;
    cout << "Another element: " << matA(0,0) << endl;    //operator ()
    //cout << "Another element: " << matC.getValue(0,1) << endl;
    try{
        matA.setValue(3, 2, 2.0);
    }
    catch( std::out_of_range & ex ){
        cout <<ex.what() << endl;
    }
    cout << "Row 1: ";
    for (auto i : matA.getRow(1)){
        cout << i << " ";
    }
    cout << endl;

    std::vector<double> new_row {-4.8, 5.3};
    matA.setRow(2, new_row);
    cout << "Row 2: ";
    for (auto i : matA.getRow(2)){
        cout << i << " ";
    }
    cout << endl;

    cout << "Column 0: " << endl;
    for (auto i : matA.getColumn(0)){
        cout << i << "\n";
    }

    std::vector<double> new_column {-2.8, 3.3, 1.4};
    matA.setColumn(1, new_column);
    cout << "Column 1: " << endl;
    for (auto i : matA.getColumn(1)){
        cout << i << "\n";
    }

    cout << "Operators: << \n Matrix A: ";
    cout << matA;
    

    matB.setElementDisplayWidth(10);
    cout << "Matrix B:" << matB;

    std::vector<size_t> dim(2);
    dim = matA.getDimensions();
    cout << "Matrix A has " << dim[0] << " rows and " << dim[1] << " columns." <<endl;

    cout << "\n \n ************************** \n";
    cout << "matA + matB = " << (matA + matB) << endl;
    cout << "matA += matB = " << (matA += matB) << endl;
    cout << "matA - matB = " << (matA - matB) << endl;
    cout << "matA -= matB = " << (matA -= matB) << endl;
    
    matA.setColumn(0, std::vector<double>{1.0, 3.0, 5.0});
    matA.setColumn(1, std::vector<double>{2.0, 4.0, 6.0});

    sd::Matrix<double> matB2(2,3,1.0);
    matB2.setRow(0, std::vector<double>{1.1, 1.2, 1.3});
    matB2.setRow(1, std::vector<double>{2.1, 2.2, 2.3});

    cout << "matA" << matA << "matB" << matB2 
         << "matA * matB" << (matA * matB2) << endl;
    
    cout << "matA * 2.0 = " << (matA * 2.0);

    cout << "matA *= 2.0 " << (matA *= 2.0);

    sd::Matrix<int> matInt(3, 2, 5);

    cout << "matA transposed: " << matA.transpose();
    
    cout << "matA<double> + matInt" << (matInt + matA );

    cout << "*********************************" << endl;
    
    sd::SquareMatrix<double> matSqA(3, 3.0);
    
    sd::SquareMatrix<double> matSqB(3);
    matSqB.setRow(0, std::vector<double>{1.0, 2.0, 3.0});
    matSqB.setRow(1, std::vector<double>{4.0, 5.0, 6.0});
    matSqB.setRow(2, std::vector<double>{7.0, 8.0, 9.0});
    
    sd::SquareMatrix<double> matSqC( matSqB );

    cout << "Square matrix A" << matSqA;
    cout << "Square matrix B" << matSqB;
    cout << "Square matrix C" << matSqC;

    sd::Matrix<double> matG(3, 3, 2.0);
    sd:: SquareMatrix matSqD( matG );
    cout << "Matrix to SquareMatrix: " << matSqD;
    cout << "Matrix + SquareMatrix: " << ( matSqD+matG );

    cout << "Minor" << matSqB.minor(1,2); 

    matSqC.setRow(0, std::vector<double>{1.5,1.8, 7.8});
    matSqC.setRow(1, std::vector<double>{-1.2, 5.4, 9.9});
    matSqC.setRow(2, std::vector<double>{-6.6, -2.2, -1.1});
    cout << "Square matrix C" << matSqC;
    cout << "Determinant = " << matSqC.det() << endl;   //202.356
    cout << "Cofactor of matrixB" << matSqB.cofactor();
    
    try{
        matSqB.inverse();
    }
    catch( std::invalid_argument & ex ){
        cout <<ex.what() << endl;
    }

    sd::SquareMatrix matSqF = matSqC.inverse(); 
    matSqF.setElementDisplayWidth( 12 );
    cout << "Inversion of matrix C" << matSqF;
    cout << "matC times its inversion " << matSqC * matSqF;  

    cout << "**********************************" << endl;
    cout << "Triangular Matrix!" << endl;

    sd::TriangularMatrix matTrA( 3, sd::TriangleType::Lower, 1.0 );
    cout << "Lower triangular matrix" << matTrA; 
    sd::TriangularMatrix matTrB( 3, sd::TriangleType::Upper, 1.0 );
    cout << "Upper triangular matrix " << matTrB; 
    matTrB( 2, 1 ) = 0.5;
    try{
        matTrB( 2, 0 ) = 1.0;
    }
    catch( std::domain_error & ex ){
        cout <<ex.what() << endl;
    }
    cout << "B( 2, 1 ) = " << matTrB( 2, 1 ) << "B( 2, 0)" << matTrB( 2, 0 ) << endl; 
    cout << "Done!" << endl;
}