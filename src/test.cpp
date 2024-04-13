#include <gtest/gtest.h>

#include "matrix.h"

TEST(EqMatrix, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  matr.setValues(5.12);
  matr2.setValues(5.12);
  ASSERT_TRUE(matr.EqMatrix(matr2) == 1);
}

TEST(EqMatrix, Test_2) {
  Matrix matr(3, 2);
  Matrix matr2(3, 3);
  matr.setValues(5.12);
  matr2.setValues(5.12);
  ASSERT_TRUE(matr.EqMatrix(matr2) == 0);
}

TEST(EqMatrix, Test_3) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  matr.setValues(5.0000001);
  matr2.setValues(5);
  ASSERT_TRUE(matr.EqMatrix(matr2) == 0);
}

TEST(EqMatrix, Test_4) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  matr.setValues(5.00000001);
  matr2.setValues(5);
  ASSERT_TRUE(matr.EqMatrix(matr2) == 1);
}

TEST(SumMatrix, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(5.2);
  matr2.setValues(5.1);
  res.setValues(10.3);
  matr.SumMatrix(matr2);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(SumMatrix, Test_2) {
  Matrix matr(2, 3);
  Matrix matr2(3, 3);
  try {
    matr.SumMatrix(matr2);
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(SumMatrix, Test_3) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(0);
  matr2.setValues(0);
  res.setValues(0);
  matr.SumMatrix(matr2);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(SubMatrix, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(5.2);
  matr2.setValues(5.1);
  res.setValues(0.1);
  matr.SubMatrix(matr2);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(SubMatrix, Test_2) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(-2.6);
  matr2.setValues(5);
  res.setValues(-7.6);
  matr.SubMatrix(matr2);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(SubMatrix, Test_3) {
  Matrix matr(2, 3);
  Matrix matr2(3, 3);
  try {
    matr.SubMatrix(matr2);
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(MulNumber, Test_1) {
  Matrix matr(3, 3);
  Matrix res(3, 3);
  matr.setValues(2.2);
  res.setValues(4.4);
  matr.MulNumber(2);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(MulNumber, Test_2) {
  Matrix matr(3, 3);
  Matrix res(3, 3);
  matr.setValues(0);
  res.setValues(0);
  matr.MulNumber(0);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(MulNumber, Test_3) {
  Matrix matr(3, 3);
  Matrix res(3, 3);
  matr.setValues(10);
  res.setValues(2);
  matr.MulNumber(0.2);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(MulMatrix, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(0);
  matr2.setValues(0);
  res.setValues(0);
  matr.MulMatrix(matr2);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(MulMatrix, Test_2) {
  Matrix matr(3, 3);
  Matrix matr2(3, 1);
  Matrix res(3, 1);
  matr.setValues(2);
  matr2.setValues(2);
  res.setValues(12);
  matr.MulMatrix(matr2);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(MulMatrix, Test_3) {
  Matrix matr(3, 2);
  Matrix matr2(3, 3);
  try {
    matr.MulMatrix(matr2);
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(Transpose, Test_1) {
  Matrix matr(3, 2);
  Matrix res(2, 3);
  matr.setValues(2);
  res.setValues(2);
  matr.Transpose();
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(CalcComlements, Test_1) {
  Matrix matr(3, 3);
  Matrix res(3, 3);
  double array1[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double array2[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  matr.setValuesWithArray(array1);
  res.setValuesWithArray(array2);
  ASSERT_TRUE(res.EqMatrix(matr.CalcComplements()) == 1);
}

TEST(CalcComlements, Test_2) {
  Matrix matr(3, 2);
  try {
    matr.CalcComplements();
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(CalcComlements, Test_3) {
  Matrix matr(1, 1);
  Matrix res(1, 1);
  matr.setValues(1);
  res.setValues(1);
  ASSERT_TRUE(res.EqMatrix(matr.CalcComplements()) == 1);
}

TEST(CalcComlements, Test_4) {
  Matrix matr(4, 4);
  Matrix res(4, 4);
  double array1[16] = {-3, 1, 8, 2, -1, 6, 4, 2, -7, 2, 4, 2, 4, 7, 2, 7};
  double array2[16] = {96,   -144, 228,  24,  24, 324, 57,  -354,
                       -232, -12,  -131, 182, 32, -48, -44, 248};
  matr.setValuesWithArray(array1);
  res.setValuesWithArray(array2);
  ASSERT_TRUE(res.EqMatrix(matr.CalcComplements()) == 1);
}

TEST(Determinant, Test_1) {
  Matrix matr(1, 1);
  matr.setValues(1);
  ASSERT_TRUE(matr.Determinant() == 1);
}

TEST(Determinant, Test_2) {
  Matrix matr(2, 3);
  try {
    matr.Determinant();
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(Determinant, Test_3) {
  Matrix matr(3, 3);
  double array1[9] = {2, 5, 2, 1, 1, 4, 6, 2, 8};
  matr.setValuesWithArray(array1);
  ASSERT_TRUE(matr.Determinant() == 72);
}

TEST(InverseMatrix, Test_1) {
  Matrix matr(3, 3);
  Matrix res(3, 3);
  double array1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double array2[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  matr.setValuesWithArray(array1);
  res.setValuesWithArray(array2);
  ASSERT_TRUE(res.EqMatrix(matr.InverseMatrix()) == 1);
}

TEST(InverseMatrix, Test_2) {
  Matrix matr(2, 3);
  try {
    matr.InverseMatrix();
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(InverseMatrix, Test_3) {
  Matrix matr(3, 3);
  double array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  matr.setValuesWithArray(array);
  try {
    matr.Determinant();
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(InverseMatrix, Test_4) {
  Matrix matr(2, 2);
  Matrix res(2, 2);
  double array1[4] = {1, 2, 3, 4};
  double array2[4] = {-2, 1, 1.5, -0.5};
  matr.setValuesWithArray(array1);
  res.setValuesWithArray(array2);
  ASSERT_TRUE(res.EqMatrix(matr.InverseMatrix()) == 1);
}

TEST(InverseMatrix, Test_5) {
  Matrix matr(3, 3);
  Matrix res(3, 3);
  double array1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double array2[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  matr.setValuesWithArray(array1);
  res.setValuesWithArray(array2);
  ASSERT_TRUE(res.EqMatrix(matr.InverseMatrix()) == 1);
}

TEST(InverseMatrix, Test_6) {
  Matrix matr(1, 1);
  Matrix res(1, 1);
  matr.setValues(1);
  res.setValues(1);
  ASSERT_TRUE(res.EqMatrix(matr.InverseMatrix()) == 1);
}

TEST(InverseMatrix, Test_7) {
  Matrix matr(1, 1);
  try {
    matr.InverseMatrix();
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(InverseMatrix, Test_8) {
  Matrix matr(1, 1);
  Matrix res(1, 1);
  matr.setValues(2);
  res.setValues(0.5);
  ASSERT_TRUE(res.EqMatrix(matr.InverseMatrix()) == 1);
}

TEST(SetRows, Test_1) {
  Matrix matr(1, 1);
  Matrix res(4, 1);
  double array[4] = {2, 0, 0, 0};
  matr.setValues(2);
  res.setValuesWithArray(array);
  matr.setRows(4);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(SetRows, Test_2) {
  Matrix matr(3, 3);
  Matrix res(1, 3);
  matr.setValues(2);
  res.setValues(2);
  matr.setRows(1);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(SetCols, Test_1) {
  Matrix matr(1, 1);
  Matrix res(1, 4);
  double array[4] = {2, 0, 0, 0};
  matr.setValues(2);
  res.setValuesWithArray(array);
  matr.setCols(4);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(SetCols, Test_2) {
  Matrix matr(3, 3);
  Matrix res(3, 1);
  matr.setValues(2);
  res.setValues(2);
  matr.setCols(1);
  ASSERT_TRUE(res.EqMatrix(matr) == 1);
}

TEST(OperatorPlus, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(2);
  matr2.setValues(5);
  res.setValues(7);
  ASSERT_TRUE(res.EqMatrix(matr + matr2) == 1);
}

TEST(OperatorPlus, Test_2) {
  Matrix matr(3, 3);
  Matrix matr2(2, 3);
  try {
    Matrix res = matr + matr2;
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(OperatorMinus, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(12);
  matr2.setValues(5);
  res.setValues(7);
  ASSERT_TRUE(res.EqMatrix(matr - matr2) == 1);
}

TEST(OperatorMinus, Test_2) {
  Matrix matr(3, 3);
  Matrix matr2(2, 3);
  try {
    Matrix res = matr - matr2;
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(OperatorMul, Test_1) {
  Matrix matr(3, 3);
  Matrix res(3, 3);
  matr.setValues(2);
  res.setValues(8);
  ASSERT_TRUE(res.EqMatrix(matr * 4) == 1);
}

TEST(OperatorMul, Test_2) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(2);
  matr2.setValues(3);
  res.setValues(18);
  ASSERT_TRUE(res.EqMatrix(matr * matr2) == 1);
}

TEST(OperatorMul, Test_3) {
  Matrix matr(3, 3);
  Matrix matr2(2, 3);
  try {
    Matrix res = matr * matr2;
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

TEST(OperatorEqual, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  matr.setValues(2);
  matr2.setValues(2);
  ASSERT_TRUE(matr == matr2);
}

TEST(OperatorPlusEqual, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(2);
  matr2.setValues(2);
  res.setValues(4);
  matr += matr2;
  ASSERT_TRUE(matr == res);
}

TEST(OperatorMinusEqual, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(4);
  matr2.setValues(2);
  res.setValues(2);
  matr -= matr2;
  ASSERT_TRUE(matr == res);
}

TEST(OperatorMulEqual, Test_1) {
  Matrix matr(3, 3);
  Matrix matr2(3, 3);
  Matrix res(3, 3);
  matr.setValues(2);
  matr2.setValues(3);
  res.setValues(18);
  matr *= matr2;
  ASSERT_TRUE(matr == res);
}

TEST(OperatorMulEqual, Test_2) {
  Matrix matr(3, 3);
  Matrix res(3, 3);
  matr.setValues(2);
  res.setValues(4);
  matr *= 2;
  ASSERT_TRUE(matr == res);
}

TEST(OperatorIndex, Test_1) {
  Matrix matr(3, 3);
  double array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  matr.setValuesWithArray(array);
  double num = matr(1, 2);
  ASSERT_TRUE(num == 2);
}

TEST(OperatorIndex, Test_2) {
  Matrix matr(3, 3);
  double array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  matr.setValuesWithArray(array);
  try {
    double num = matr(5, 3);
  } catch (const std::exception& e) {
    ASSERT_TRUE(1 == 1);
  }
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}