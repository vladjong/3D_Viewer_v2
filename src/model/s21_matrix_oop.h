#pragma once

#include <cmath>
#include <iostream>

namespace s21 {
class S21Matrix {
    friend S21Matrix operator*(const double value, const S21Matrix& other);
    friend S21Matrix operator*(const S21Matrix& other, const double value);

 private:
    int _rows, _cols;
    double** _matrix;

 private:
    bool eq_matrix_loop(const S21Matrix& other);
    S21Matrix calculate_minor(int rows, int cols);
    void init_matrix();
    void delate_matrix();

 public:
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();

    int getRows() const;
    int getCols() const;
    void setRows(int number);
    void setCols(int number);

    S21Matrix operator+(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
    S21Matrix operator*(const S21Matrix& other);
    bool operator==(const S21Matrix& other);
    S21Matrix& operator=(const S21Matrix& other);
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix& operator*=(const double value);
    double& operator()(int row, int col);

    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose();
    S21Matrix calc_complements();
    double determinant();
    S21Matrix inverse_matrix();

    void fill_matrix();
};

}  // namespace s21
