# Interpolation Techniques
* [Polynomial Interpolation](https://en.wikipedia.org/wiki/Polynomial_interpolation)

   Polynomial Interpolation involves finding the coefficients of a polynomial that passes through a given set of data points. QR decomposition is used to solve the linear system of equations that arises from the interpolation problem.
  
  **Steps:**

  - Suppose we have (n + 1) data points ($x_{i}$, $y_{i}$) for $i$ = 0, 1, ..., n.
  - We want to find a Polynomial **P($x$)** = $a_{0}$ + $a_{1}x$ + $a_{2}x^{2}$ + ... + $a_{n}x^{n}$ that passes through above points.
  - Form the Vandermonde matrix **V** using the data points:
    <table>
     <tr>
       <td><img src="https://drive.google.com/uc?export=view&id=11H7af5Lagj5ilLILzIvXBmoQM4e1S3vb" height="100%" width="100%"/></td>
     </tr>
    </table>
    
  - Perform [QR decomposition](https://github.com/anubhav1772/Mathematics-for-Robotics/blob/main/LinearAlgebra/QRDecomposition.cpp) on the Vandermonde matrix **V**.
 
    `V = QR`, where **Q** is an orthogonal matrix and **R** is an upper triangular matrix.
  - Let $y$ be the column vector of $y_{i}$ values.
    <table>
     <tr>
       <td><img src="https://drive.google.com/uc?export=view&id=1AR2sKlrx3qvrFS4AtmSs8kCHVPEQlCzh" height="100%" width="100%"/></td>
     </tr>
    </table>
  - Solve the system: **R**${x}$ = $Q^{T}y$ for the column vector $x$ of unknown coefficients ($a_{0}$, $a_{1}$, ..., $a_{n}$).
  - Use the value of the coefficients ($a_{0}$, $a_{1}$, ..., $a_{n}$) obtained from the solution to construct the polynomial **P($x$)**.


   
