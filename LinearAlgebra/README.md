# Linear Algebra Techniques
1. [Cholesky Decomposition](https://en.wikipedia.org/wiki/Cholesky_decomposition)

   One important application is in calculating the square root of a positive definite matrix. It's faster than the LU decomposition.

   A = $\sqrt{P}$ <= AᵀA = P

2. [Rank of a matrix](https://en.wikipedia.org/wiki/Rank_(linear_algebra))

   When applied to floating point computations on computers, basic Gaussian elimination (LU decomposition) can be unreliable, and a rank-revealing decomposition should be used instead. An effective alternative is the singular value decomposition (SVD), but there are other less expensive choices, such as QR decomposition with pivoting (so-called rank-revealing QR factorization), which are still more numerically robust than Gaussian elimination. Numerical determination of rank requires a criterion for deciding when a value, such as a singular value from the SVD, should be treated as zero, a practical choice which depends on both the matrix and the application. 

3. [QR Decomposition](https://en.wikipedia.org/wiki/QR_decomposition)

   A decomposition of a matrix **A** into a product `A = QR` of an orthonormal matrix **Q** and an upper triangular matrix **R**. QR decomposition is often used to solve the linear least squares problem and is the basis for a particular eigenvalue algorithm, the QR algorithm.
   
   - [Householder Method](https://atozmath.com/example/MatrixEv.aspx?q=qrdecomphh&q1=E1)
   - [Gram Schmidt Method](https://atozmath.com/example/MatrixEv.aspx?q=qrdecompgs&q1=E1)

5. [LU Decomposition](https://en.wikipedia.org/wiki/LU_decomposition)
   
   Let A be a square matrix. An LU factorization refers to the factorization of **A**, with proper row and/or column orderings or permutations, into two factors – a lower triangular matrix **L** and an upper triangular matrix **U**:

   `A = LU`
   
   In the lower triangular matrix all elements above the diagonal are zero, in the upper triangular matrix, all the elements below the diagonal are zero.
   
