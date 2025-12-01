#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::cout, std::cin, std::endl;

using intVector = std::vector< int >;
using intMatrix = std::vector< intVector >;

int sum_ev_col_unev_row(const intMatrix& A)
{
    //Checking if input matrix is correct:
    if (A.size() <= 0)
    {
        return -1;
    }
    //Calculating sum:
    int sum{};
    for (int r{}; r<A.size(); ++r)
    {
        for (int c{}; c<A[0].size(); ++c)
        {
            if( (r%2 == 1) || (c%2 == 0) )
            {
                sum += A[r][c];
            } 
        }
    }
    return sum;
}

int main()
{
    int col {}, row{};
    cout << "Enter number of rows and columns:\n";
    cin >> row;
    cin >> col;
    
    // Random number generator's configuration:
    srand(static_cast<unsigned int>(time(0)));

    //Initialization of matrix A containing only zeros:
    intMatrix A (row, intVector(col,0) );

    //Filling matrix A with pseudo-random numbers
    //(References are needed - in other case the loop operates
    //with copies of rows and columns of matrix A;
    //vide: the meme at the bottom of UPEL page ;) ).
    for ( auto& r : A )
    {
        for (auto& c : r)
        {
            c= rand() % 10;
        }

    }
    //Displaying matrix A;
    cout << "\nMatrix A:\n";
    for ( auto r : A )
    {
        for (auto c : r)
        {
            cout << c << " ";
        }
        cout << endl;

    }
    
    //Calculating the sum of  the elements of matrix A,
    //that belong to uneven rows and eben columns:
    int sum {};
    sum = sum_ev_col_unev_row(A);
    
    cout << "\nSum of  the elements of matrix A,\nthat belong to uneven rows and eben columns: ";
    cout << sum << endl;
    
}

/*Example of executing the program:
Result on the screen:
Enter number of rows and columns: 
4
5
6 1 4 3 1 
6 0 5 9 9 
3 8 3 8 4 
3 8 8 5 9 
Sum of  the elements of matrix A, that belong 
to uneven rows and eben columns: 83 

Which is correct, because:
6+4+1+6+0+5+9+9+3+3+4+3+8+8+5+9=83

*/
