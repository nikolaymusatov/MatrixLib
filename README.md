# MatrixLib
In this project my own library for processing numerical matrices was implemented in C++ programming language using the object-oriented approach.
- The project is developed in C++ language of C++17 standard using gcc compiler
- Made it as a static library (with matrix.h header file)
- Implemented the operations described below.
- Full coverage of library functions code with unit-tests  was prepared using the GTest library
- Makefile for building the library and tests (with targets all, clean, test, matrix.a) is provided.

# Matrix operations

There is a description of the matrix operations below that were implemented in the developing library.

| Operation | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const Matrix& other)` | Checks matrices for equality with each other |  |
| `void SumMatrix(const Matrix& other)` | Adds the second matrix to the current one | different matrix dimensions |
| `void SubMatrix(const Matrix& other)` | Subtracts another matrix from the current one | different matrix dimensions |
| `void MulNumber(const double num) ` | Multiplies the current matrix by a number |  |
| `void MulMatrix(const Matrix& other)` | Multiplies the current matrix by the second matrix | the number of columns of the first matrix is not equal to the number of rows of the second matrix |
| `Matrix Transpose()` | Creates a new transposed matrix from the current one and returns it |  |
| `Matrix CalcComplements()` | Calculates the algebraic addition matrix of the current one and returns it | the matrix is not square |
| `double Determinant()` | Calculates and returns the determinant of the current matrix | the matrix is not square |
| `Matrix InverseMatrix()` | Calculates and returns the inverse matrix | matrix determinant is 0 |

Apart from those operations, constructors and destructors were also implemented:

| Method | Description |
| ----------- | ----------- |
| `Matrix()` | A basic constructor that initialises a matrix of some predefined dimension |  
| `Matrix(int rows, int cols) ` | Parametrized constructor with number of rows and columns |
| `Matrix(const Matrix& other)` | Copy constructor |
| `Matrix(Matrix&& other)` | Move constructor |
| `~Matrix()` | Destructor |

And also the following operators were overloaded:

| Operator | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `+`      | Addition of two matrices | different matrix dimensions |
| `-`   | Subtraction of one matrix from another | different matrix dimensions |
| `*`  | Matrix multiplication and matrix multiplication by a number | the number of columns of the first matrix does not equal the number of rows of the second matrix |
| `==`  | Checks for matrices equality (`EqMatrix`) | |
| `=`  | Assignment of values from one matrix to another one | |
| `+=`  | Addition assignment (`SumMatrix`) | different matrix dimensions |
| `-=`  | Difference assignment (`SubMatrix`) | different matrix dimensions |
| `*=`  | Multiplication assignment (`MulMatrix`/`MulNumber`) | the number of columns of the first matrix does not equal the number of rows of the second matrix |
| `(int i, int j)`  | Indexation by matrix elements (row, column) | index is outside the matrix |
