#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <complex>

using Eigen::MatrixXd;
using Eigen::VectorXd;

using std::cout;
using std::endl;
using namespace std::literals;

/*
* Polynomial Interpolation 
* - finding the coefficients of a polynomial that passes through a given set of data points
* - QR decomposition is used to solve the linear system of equations that arises from the 
*   interpolation problem.
* - QR decomposition can be solved either using   
*   1. Householder method (we used this below)
*   2. Gram Schmidt method
*/

// Evaluate a polynomial
double polyeval(VectorXd coeffs, double x)
{
    double y = 0.0;
    for(int i = 0; i < coeffs.size(); i++)
    {
        y += coeffs[i] * pow(x, i);
    }
    return y;
}

// Fit a polynomial
VectorXd polyfit(VectorXd xvals, VectorXd yvals, int order)
{
    assert(xvals.size() == yvals.size());
    assert(order >= 1 && order <= xvals.size() - 1);

    MatrixXd A(xvals.size(), order + 1);

    for(int i = 0; i < xvals.size(); i++)
    {
        A(i, 0) = 1.0;
    }

    for(int j = 0; j < xvals.size(); j++)
    {
        for(int i = 0; i < order; i++)
        {
            A(j, i + 1) = A(j, i) * xvals(j);
        }
    }

    VectorXd coeffs = A.householderQr().solve(yvals);
    return coeffs;
}

int main()
{
    VectorXd xvals(6), yvals(6);
    // x waypoint coords
    xvals << 9.261977, -2.06803, -19.6663, -36.868, -51.6263, -66.3482;
    // y waypoint coords
    yvals << 5.17, -2.25, -15.306, -29.46, -42.85, -57.6116;

    // Interpolate a polynomial of degree 3
    // there are (n + 1) number of coefficients in a polynomial of degree/order n
    int order = 3;
    VectorXd coeffs = polyfit(xvals, yvals, order);
    cout << "Polynomial Coefficients: \n" << endl << coeffs << endl;

    // test
    for(double x = 0; x <= 10; x++)
    {
        cout << polyeval(coeffs, x) << " ";
    }
    return 0;  
}