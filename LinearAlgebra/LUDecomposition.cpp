#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <complex>

using Eigen::MatrixXd;
//using Eigen::PartialPivLU;
using Eigen::FullPivLU;
using Eigen::StrictlyLower;
using Eigen::Upper;

using std::cout;
using std::endl;
using namespace std::literals;

/*
*  LU decomposition   
*/

int main()
{   
    int n = 3;
    MatrixXd A(n, n), L(n, n), U(n, n);
    A << 25, 5, 1,
         64, 8, 1,
         144, 12, 1;

    /*
    PartialPivLU<MatrixXd> lu_decomp(A);
    MatrixXd LU = lu_decomp.matrixLU();
    */

    FullPivLU<MatrixXd> lu_decomp(A);

    L = MatrixXd::Identity(n, n);
    L.block<3, 3>(0, 0).triangularView<StrictlyLower>() = lu_decomp.matrixLU();
    U = lu_decomp.matrixLU().triangularView<Upper>();

    cout << "Matrix A: " << endl << A << endl;
    cout << "Matrix L: " << endl << L << endl;
    cout << "Matrix U: " << endl << U << endl;

    // Reconstruct A from LU decomposition
    // A_ = (Inverse P) * L * U * (Inverse Q)
    //      where P and Q are permutation matrces
    // A_ = A (Reconstructed matrix A_ should be equal to original A)
    MatrixXd A_ = lu_decomp.permutationP().inverse() * L * U * lu_decomp.permutationQ().inverse();
    cout << "Reconstructed A: " << endl << A_ << endl;
    return 0;
}

