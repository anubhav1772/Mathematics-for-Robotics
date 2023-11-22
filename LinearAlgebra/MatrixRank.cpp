#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <complex>

using Eigen::MatrixXd;
using Eigen::FullPivLU;
using Eigen::JacobiSVD;
using Eigen::ComputeThinU;
using Eigen::ComputeThinV;

using std::cout;
using std::endl;
using namespace std::literals;

/*
*  Rank of a matrix
*  1. LU decomposition method
*     - A = LU, 
*       where L = lower triangular matrix, U = upper triangular matrix
*     - Transform U to echelon form
*     - Rank = Number of non-zero rows in the echelon form of U.
*  2. SVD decomposition method
*     - Extract the singular values of the matrix and then counts how many 
*       are above a given tolerance to determine the rank.
*     - We can adjust the tolerance variable based on the precision we desire.
*/

int main()
{
    MatrixXd matrix(3, 3);
    matrix << 1, 2, 3,
              4, 5, 6,
              7, 8, 9;

    // Method 1: Using LU decomposition
    FullPivLU<MatrixXd> lu_decomp(matrix);
    int rank = lu_decomp.rank();
    cout << "Matrix Rank: " << rank << endl;

    // Method 2: Using SVD decomposition
    JacobiSVD<MatrixXd> svd(matrix, ComputeThinU | ComputeThinV);

    double tolerance = 1e-10;
    rank = 0;
    for(int i = 0; i<svd.singularValues().size(); i++)
    {
        if(svd.singularValues()(i) > tolerance)
        {
            rank++;
        }
    }
    cout << "Matrix Rank: " << rank << endl;
    return 0;
}

