#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_
#define EPS 1e-7

class Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  // constructors & destructor
  Matrix();
  Matrix(int rows, int cols);
  Matrix(const Matrix& other);
  Matrix& operator=(const Matrix& matrix);
  Matrix(Matrix&& other);
  Matrix& operator=(Matrix&& matrix);
  ~Matrix();

  //  accecors and mutators
  int getRows();
  int getCols();
  void setRows(int rows);
  void setCols(int cols);

  // library methods
  bool EqMatrix(const Matrix& other);
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const Matrix& other);
  Matrix Transpose();
  Matrix CalcComplements();
  double Determinant();
  Matrix getMinor(int elem_row, int elem_col);
  Matrix InverseMatrix();

  // opeartors
  Matrix operator+(Matrix& matrix);
  Matrix operator-(Matrix& matrix);
  Matrix operator*(Matrix& matrix);
  Matrix operator*(double number);
  bool operator==(Matrix& matrix);
  void operator=(Matrix& matrix);
  void operator+=(Matrix& matrix);
  void operator-=(Matrix& matrix);
  void operator*=(Matrix& matrix);
  void operator*=(double number);
  double operator()(int i, int j);

  // utils
  void setValues(double value);
  void setValues();
  void setValuesWithArray(double array[]);
};

#endif  // SRC_MATRIX_H_
