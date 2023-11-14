#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <complex>

using Eigen::MatrixXcf;
using Eigen::LLT;

using std::cout;
using std::endl;
using namespace std::literals;

/*
* Finding Cholesky Decomposition/Factorization of a Hermite, psoitive definite matrix A
*   A = L*L^
*   where   L  => lower triangular matrix(A)
*           L^ => conjugate transpose matrix(L)
*
* Diagonal element of L:
*  L(i, i) = √(A(i, i) - ∑(j<i) L(i, j)*L(i, j)^) 
*
* Non-diagonal element of L:
*  L(t, i) = (1/L(i, i))(A(t, i) - ∑(j<i) L(t, j)*L(i, j)^)    
*/

int main()
{
    int n = 2;
    MatrixXcf A(n, n);
    A << 4.0f, 4.0f + 10.0if,
         4.0f - 10.0if, 29.0f;

    //A << 81.0f, 2.0if,
    //    9.0if, 45.0f;

    //A << 36.0f, 12.0if,
    //    -12.0if, 42.0f;

    //A << 1.0f, 2.0f, 5.0f,
    //     2.0f, 13.0f, 13.0f,
    //     5.0f, 13.0f, 30.0f;

    //A << 4, 12, -16,
    //    12, 37, -43,
    //    -16, -43, 98;

    MatrixXcf L;
    L.resize(n, n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++) // covers all cells <= diagonal cell (lower triangular)
        {
            std::complex<float> sum(0, 0);
            for(int t=0; t<j; t++)
            {
                if(i==j) // diagonal case
                {
                    sum += L(j, t)*(conj(L(j, t)));
                }
                else    // non-diagonal case
                {
                    sum += L(i, t)*(conj(L(j, t)));
                }  
            }
            if(i==j) // diagonal case
            {
                L(i, i) = sqrt(A(i, i) - sum);
            }
            else    // non-diagonal case
            {
                L(i, j) = (A(i, j) - sum)/L(j, j);
            }     
        }   
    }
    cout << "A (Original matrix):\n " << A << endl;
    cout << "L (Positive diagonal lower triangular matrix):\n " << L << endl;
    cout << "L^ (Conjugate transpose of L):\n " << L.conjugate().transpose() << endl;

    // Alternate method (Cholesky decomposition)
    // LLT<MatrixXcf> lltOfA(A);
    // L = lltOfA.matrixL();
    // L = A.llt().matrixL();
    // cout << "L\n " << L << endl;
    return 0;
}

