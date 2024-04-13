#include "matrix.h"

#include <math.h>

#include <exception>
#include <iostream>

void Matrix::print() {
  for (int r = 0; r < this->rows_; r++) {
    for (int c = 0; c < this->cols_; c++)
      std::cout << this->matrix_[r][c] << '\t';
    std::cout << std::endl;
  }
}

void Matrix::setValues(double value) {
  for (int r = 0; r < this->rows_; r++)
    for (int c = 0; c < this->cols_; c++) this->matrix_[r][c] = value;
}

void Matrix::setValues() {
  for (int r = 0; r < this->rows_; r++)
    for (int c = 0; c < this->cols_; c++) this->matrix_[r][c] = rand() % 10;
}

void Matrix::setValuesWithArray(double array[]) {
  int i = 0;
  for (int r = 0; r < this->rows_; r++)
    for (int c = 0; c < this->cols_; c++) {
      this->matrix_[r][c] = array[i];
      i++;
    }
}

Matrix::Matrix() : rows_(3), cols_(3) {
  matrix_ = new double*[rows_];
  for (int r = 0; r < rows_; r++) {
    matrix_[r] = new double[cols_];
    for (int c = 0; c < cols_; c++) matrix_[r][c] = 0;
  }
}

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  matrix_ = new double*[rows];
  for (int r = 0; r < rows; r++) {
    matrix_[r] = new double[cols];
    for (int c = 0; c < cols; c++) matrix_[r][c] = 0;
  }
}

Matrix::Matrix(const Matrix& other) : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double*[rows_];
  for (int r = 0; r < rows_; r++) matrix_[r] = new double[cols_];
  for (int r = 0; r < rows_; r++)
    for (int c = 0; c < cols_; c++) this->matrix_[r][c] = other.matrix_[r][c];
}

Matrix& Matrix::operator=(const Matrix& matrix) {
  if (this == &matrix) return *this;
  double** tmp = new double*[matrix.rows_];
  for (int r = 0; r < matrix.rows_; r++) tmp[r] = new double[matrix.cols_];
  for (int r = 0; r < matrix.rows_; r++)
    for (int c = 0; c < matrix.cols_; c++) tmp[r][c] = matrix.matrix_[r][c];
  for (int r = 0; r < this->rows_; r++) delete[] matrix_[r];
  delete[] matrix_;
  this->matrix_ = tmp;
  return *this;
}

Matrix::Matrix(Matrix&& other) {
  this->matrix_ = other.matrix_;
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  other.matrix_ = nullptr;
  other.rows_ = other.cols_ = 0;
}

Matrix& Matrix::operator=(Matrix&& matrix) {
  if (this == &matrix) return *this;
  for (int r = 0; r < rows_; r++) delete[] matrix_[r];
  delete[] matrix_;
  this->rows_ = matrix.rows_;
  this->cols_ = matrix.cols_;
  this->matrix_ = matrix.matrix_;
  matrix.matrix_ = nullptr;
  return *this;
}

Matrix::~Matrix() {
  for (int r = 0; r < rows_; r++) delete[] matrix_[r];
  delete[] matrix_;
}

int Matrix::getRows() { return rows_; }

int Matrix::getCols() { return cols_; }

void Matrix::setRows(int rows) {
  double** matrix = new double*[rows];
  for (int r = 0; r < rows; r++) matrix[r] = new double[this->cols_];
  for (int r = 0; r < rows; r++)
    for (int c = 0; c < this->cols_; c++)
      if (r < this->rows_) matrix[r][c] = this->matrix_[r][c];
  for (int r = 0; r < rows_; r++) delete[] this->matrix_[r];
  delete[] this->matrix_;
  this->matrix_ = matrix;
  rows_ = rows;
}

void Matrix::setCols(int cols) {
  double** matrix = new double*[rows_];
  for (int r = 0; r < rows_; r++) matrix[r] = new double[cols];
  for (int r = 0; r < this->rows_; r++)
    for (int c = 0; c < cols; c++)
      if (c < this->cols_) matrix[r][c] = this->matrix_[r][c];
  for (int r = 0; r < rows_; r++) delete[] this->matrix_[r];
  delete[] this->matrix_;
  this->matrix_ = matrix;
  cols_ = cols;
}

bool Matrix::EqMatrix(const Matrix& other) {
  int return_code = false;
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    return_code = true;
    for (int r = 0; r < this->rows_; r++)
      for (int c = 0; c < this->cols_; c++)
        if (fabs(this->matrix_[r][c] - other.matrix_[r][c]) >= EPS)
          return_code = false;
  }
  return return_code;
}

void Matrix::SumMatrix(const Matrix& other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_)
    throw std::exception();
  else
    for (int r = 0; r < this->rows_; r++)
      for (int c = 0; c < this->cols_; c++)
        this->matrix_[r][c] = this->matrix_[r][c] + other.matrix_[r][c];
}

void Matrix::SubMatrix(const Matrix& other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_)
    throw std::exception();
  else
    for (int r = 0; r < this->rows_; r++)
      for (int c = 0; c < this->cols_; c++)
        this->matrix_[r][c] = this->matrix_[r][c] - other.matrix_[r][c];
}

void Matrix::MulNumber(const double num) {
  for (int r = 0; r < this->rows_; r++)
    for (int c = 0; c < this->cols_; c++)
      this->matrix_[r][c] = this->matrix_[r][c] * num;
}

void Matrix::MulMatrix(const Matrix& other) {
  if (this->cols_ != other.rows_)
    throw std::exception();
  else {
    double** tmp = this->matrix_;
    int rows = this->rows_;
    this->matrix_ = new double*[rows];
    for (int r = 0; r < rows; r++) matrix_[r] = new double[other.cols_];
    for (int c = 0; c < this->cols_; c++)
      for (int a = 0; a < this->rows_; a++)
        for (int b = 0; b < other.cols_; b++)
          this->matrix_[a][b] += tmp[a][c] * other.matrix_[c][b];
    this->cols_ = other.cols_;
    for (int r = 0; r < rows; r++) delete[] tmp[r];
    delete[] tmp;
  }
}

Matrix Matrix::Transpose() {
  double** tmp = this->matrix_;
  int cols = this->rows_;
  int rows = this->cols_;
  this->matrix_ = new double*[rows];
  for (int r = 0; r < rows; r++) matrix_[r] = new double[cols];
  this->rows_ = rows;
  this->cols_ = cols;
  for (int r = 0; r < rows; r++)
    for (int c = 0; c < cols; c++) this->matrix_[r][c] = tmp[c][r];
  for (int r = 0; r < cols; r++) delete[] tmp[r];
  delete[] tmp;
  return *this;
}

Matrix Matrix::CalcComplements() {
  if (this->rows_ != this->cols_) throw std::exception();
  if (this->rows_ == 1)
    return *this;
  else {
    Matrix tmp = Matrix(*this);
    for (int r = 0; r < this->rows_; r++)
      for (int c = 0; c < this->cols_; c++) {
        Matrix minor = tmp.getMinor(r, c);
        double determinant = minor.Determinant();
        int sign = (r + c + 2) % 2 == 0 ? 1 : -1;
        this->matrix_[r][c] = sign * determinant;
      }
  }
  return *this;
}

double Matrix::Determinant() {
  double determinant = 0;
  double result = 0;
  if (this->rows_ != this->cols_) throw std::exception();
  if (this->rows_ == 1)
    result = this->matrix_[0][0];
  else if (this->rows_ == 2)
    result = this->matrix_[0][0] * this->matrix_[1][1] -
             this->matrix_[0][1] * this->matrix_[1][0];
  else
    for (int c = 0; c < this->cols_; c++) {
      Matrix minor = this->getMinor(0, c);
      determinant = minor.Determinant();
      int sign = (c + 1) % 2 == 0 ? -1 : 1;
      result += this->matrix_[0][c] * sign * determinant;
    }
  return result;
}

Matrix Matrix::InverseMatrix() {
  double determinant = this->Determinant();
  if (!determinant) throw std ::exception();
  if (this->rows_ == 1) {
    this->matrix_[0][0] = 1 / this->matrix_[0][0];
    return *this;
  } else {
    Matrix compMatr = this->CalcComplements();
    Matrix tranMatr = compMatr.Transpose();
    tranMatr.MulNumber(1 / determinant);
    return tranMatr;
  }
}

Matrix Matrix::getMinor(int elem_row, int elem_col) {
  Matrix result(this->rows_ - 1, this->cols_ - 1);
  for (int r = 0, rm = 0; r < this->rows_; r++)
    for (int c = 0, cm = 0; c < this->cols_; c++) {
      if (r != elem_row && c != elem_col) {
        result.matrix_[rm][cm] = this->matrix_[r][c];
        cm++;
        if (cm == result.rows_) {
          cm = 0;
          rm++;
        }
      }
    }
  return result;
}

Matrix Matrix::operator+(Matrix& matrix) {
  if (this->rows_ != matrix.rows_ || this->cols_ != matrix.cols_)
    throw std::exception();
  Matrix res(matrix.rows_, matrix.cols_);
  for (int r = 0; r < this->rows_; r++)
    for (int c = 0; c < this->cols_; c++)
      res.matrix_[r][c] = this->matrix_[r][c] + matrix.matrix_[r][c];
  return res;
}

Matrix Matrix::operator-(Matrix& matrix) {
  if (this->rows_ != matrix.rows_ || this->cols_ != matrix.cols_)
    throw std::exception();
  Matrix res(matrix.rows_, matrix.cols_);
  for (int r = 0; r < this->rows_; r++)
    for (int c = 0; c < this->cols_; c++)
      res.matrix_[r][c] = this->matrix_[r][c] - matrix.matrix_[r][c];
  return res;
}

Matrix Matrix::operator*(Matrix& matrix) {
  if (this->cols_ != matrix.rows_) throw std::exception();
  Matrix res(this->rows_, matrix.cols_);
  for (int c = 0; c < this->cols_; c++)
    for (int a = 0; a < this->rows_; a++)
      for (int b = 0; b < matrix.cols_; b++)
        res.matrix_[a][b] += this->matrix_[a][c] * matrix.matrix_[c][b];
  return res;
}

Matrix Matrix::operator*(double number) {
  Matrix res(this->rows_, this->cols_);
  for (int r = 0; r < this->rows_; r++)
    for (int c = 0; c < this->cols_; c++)
      res.matrix_[r][c] = this->matrix_[r][c] * number;
  return res;
}

bool Matrix::operator==(Matrix& matrix) { return this->EqMatrix(matrix); }

void Matrix::operator=(Matrix& matrix) {
  for (int r = 0; r < this->rows_; r++)
    for (int c = 0; c < this->cols_; c++)
      if (r < matrix.rows_ && c < matrix.cols_)
        this->matrix_[r][c] = matrix.matrix_[r][c];
      else
        this->matrix_[r][c] = 0;
}

void Matrix::operator+=(Matrix& matrix) { this->SumMatrix(matrix); }

void Matrix::operator-=(Matrix& matrix) { this->SubMatrix(matrix); }

void Matrix::operator*=(Matrix& matrix) { this->MulMatrix(matrix); }

void Matrix::operator*=(double number) { this->MulNumber(number); }

double Matrix::operator()(int i, int j) {
  if (i - 1 >= this->rows_ || j - 1 >= this->cols_) throw std::exception();
  return this->matrix_[i - 1][j - 1];
}
