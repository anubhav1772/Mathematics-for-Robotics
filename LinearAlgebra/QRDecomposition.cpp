#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <complex>

using Eigen::MatrixXf;
using Eigen::HouseholderQR;
using Eigen::Upper;

using std::cout;
using std::endl;
using namespace std::literals;

/*
* QR decomposition (using Householder Method)
* Example - https://atozmath.com/example/MatrixEv.aspx?q=qrdecomphh&q1=E1
* Eigen documentation - https://eigen.tuxfamily.org/dox/classEigen_1_1HouseholderQR.html
* Alternate: Gram Schmidt Method
* Example - https://atozmath.com/example/MatrixEv.aspx?q=qrdecompgs&q1=E1
*/

int main()
{   
    MatrixXf A(4, 3);
    A << 1, -1, 4,
         1, 4, -2,
         1, 4, 2,
         1, -1, 0;

    HouseholderQR<MatrixXf> qr(A);
    MatrixXf Q = qr.householderQ();
    MatrixXf R = qr.matrixQR().triangularView<Upper>();

    cout << "A: " << endl << A << endl;
    cout << "Q: " << endl << Q << endl;
    cout << "R: " << endl << R << endl;
    cout << "Reconstructed A: " << endl << Q*R << endl;
    return 0;
}

