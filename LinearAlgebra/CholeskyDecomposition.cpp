#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <complex>

using Eigen::MatrixXcf;

using std::cout;
using std::endl;
using namespace std::literals;

/*
* Finding Cholesky Decomposition/Factorization of a Hermite, psoitive definite matrix A
*   A = L*L^
*   where   L  => lower triangular matrix(A)
            L^ => conjugate transpose matrix(L)

    Diagonal element of L:
    L(i, i) = √(A(i, i) - ∑(j<i) L(i, j)*L(i, j)^) 

    Non-diagonal element of L:
    L(t, i) = (1/L(i, i))(A(t, i) - ∑(j<i) L(t, j)*L(i, j)^)
    
*/

int main()
{
    MatrixXcf A(2, 2);
    A << 81.0f, 2.0if,
        9.0if, 45.0;

    MatrixXcf L;
    int n = A.rows();
    L.resize(n, n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++) // covers all cells <= diagonal cell (lower triangular)
        {
            std::complex<float> sum(0, 0);
            for(int t=0; t<j; t++)
            {
                sum += L(j, t)*(conj(L(j, t)));
            }
            if(i==j) // diagonal case
            {
                L(i, i) = sqrt(A(i, i) - sum);
            }
            else    // non-diagonal case
            {
                L(i, j) = (1/L(j, j).real())*(A(i, j) - sum);
            }     
        }   
    }
    cout << "A (Original matrix):\n " << A << endl;
    cout << "L (Positive diagonal lower triangular matrix):\n " << L << endl;
    cout << "L^ (Conjugate transpose of L):\n " << L.conjugate().transpose() << endl;
    return 0;
}

