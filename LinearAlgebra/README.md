# Linear Algebra Techniques
1. [Cholesky Decomposition](https://en.wikipedia.org/wiki/Cholesky_decomposition)

   One important application is in calculating the square root of a positive definite matrix. It's faster than the LU decomposition.

   A = $\sqrt{P}$ <= AᵀA = P

2. [Rank of a matrix](https://en.wikipedia.org/wiki/Rank_(linear_algebra))

   When applied to floating point computations on computers, basic Gaussian elimination (LU decomposition) can be unreliable, and a rank-revealing decomposition should be used instead. An effective alternative is the singular value decomposition (SVD), but there are other less expensive choices, such as QR decomposition with pivoting (so-called rank-revealing QR factorization), which are still more numerically robust than Gaussian elimination. Numerical determination of rank requires a criterion for deciding when a value, such as a singular value from the SVD, should be treated as zero, a practical choice which depends on both the matrix and the application. 
