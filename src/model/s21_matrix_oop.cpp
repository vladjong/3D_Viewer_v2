#include "s21_matrix_oop.h"

namespace s21 {

S21Matrix::S21Matrix() {
    _rows = 4;
    _cols = 4;
    init_matrix();
}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
    if (_rows <= 0 || _cols <= 0) {
        throw std::out_of_range("Incorrect input, matrices should have the same size");
    }
    init_matrix();
}

S21Matrix::S21Matrix(const S21Matrix& other) : _rows(other._rows), _cols(other._cols) {
    init_matrix();
    *this = other;
}

S21Matrix::S21Matrix(S21Matrix&& other) : _rows(0), _cols(0), _matrix(nullptr) {
    std::swap(_rows, other._rows);
    std::swap(_cols, other._cols);
    std::swap(_matrix, other._matrix);
}

S21Matrix::~S21Matrix() {
    if (_matrix) {
        delate_matrix();
    }
}

int S21Matrix::getRows() const { return _rows; }

int S21Matrix::getCols() const { return _cols; }

void S21Matrix::setRows(int number) { _rows = number; }

void S21Matrix::setCols(int number) { _cols = number; }

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    bool resultEqual = false;
    if (other._cols != _cols || other._rows != _rows) {
        return resultEqual;
    }
    resultEqual = eq_matrix_loop(other);
    return resultEqual;
}

bool check_eps(double numberOne, double numberTwo) { return std::fabs(numberOne - numberTwo) < 1E-7; }

bool S21Matrix::eq_matrix_loop(const S21Matrix& other) {
    bool resultEqual = true;
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            if (_matrix[i][j] != other._matrix[i][j]) {
                return resultEqual = check_eps(_matrix[i][j], other._matrix[i][j]);
            }
        }
    }
    return resultEqual;
}

void S21Matrix::sum_matrix(const S21Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range("Incorrect input, matrices should have the same size");
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
        }
    }
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        throw std::out_of_range("Incorrect input, matrices should have the same size");
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
        }
    }
}

void S21Matrix::mul_number(const double num) {
    if (std::isnan(num) || std::isinf(num)) {
        throw std::out_of_range("Incorrect input, number should have correct value");
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] *= num;
        }
    }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
    if (_cols != other._rows) {
        throw std::out_of_range("Incorrect input, intput matrices should have same cols equal rows");
    }
    S21Matrix matrixTemp(_rows, other._cols);
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < other._cols; j++) {
            for (int k = 0; k < _cols; k++) {
                matrixTemp._matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
            }
        }
    }
    *this = matrixTemp;
}

S21Matrix S21Matrix::transpose() {
    S21Matrix matrixResult(_cols, _rows);
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            matrixResult._matrix[j][i] = _matrix[i][j];
        }
    }
    return matrixResult;
}

S21Matrix S21Matrix::calculate_minor(int rows, int cols) {
    S21Matrix matrixResult(_rows - 1, _cols - 1);
    int rowsTemp = 0;
    for (int i = 0; i < matrixResult._rows; i++) {
        if (i == rows) {
            rowsTemp = 1;
        }
        int colsTemp = 0;
        for (int j = 0; j < matrixResult._cols; j++) {
            if (j == cols) {
                colsTemp = 1;
            }
            matrixResult._matrix[i][j] = _matrix[i + rowsTemp][j + colsTemp];
        }
    }
    return matrixResult;
}

S21Matrix S21Matrix::calc_complements() {
    S21Matrix matrixResult(_rows, _cols);
    if (_rows != _cols && _rows <= 1) {
        throw std::out_of_range("Incorrect input, matrices should have the same size");
    }
    for (int i = 0; i < _cols; i++) {
        for (int j = 0; j < _rows; j++) {
            S21Matrix matrixMinor = calculate_minor(i, j);
            matrixResult._matrix[i][j] = pow(-1.0, i + j) * matrixMinor.determinant();
        }
    }
    return matrixResult;
}

double S21Matrix::determinant() {
    double determinantResult = 0.0;
    if (_rows != _cols || _rows <= 0) {
        throw std::out_of_range("Incorrect input, matrices should have the same size");
    }
    if (_rows == 1) {
        determinantResult = _matrix[0][0];
    } else if (_rows == 2) {
        determinantResult = _matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0];
    } else {
        for (int i = 0; i < _rows; i++) {
            S21Matrix MatrixMinor = calculate_minor(0, i);
            determinantResult += pow(-1.0, i) * _matrix[0][i] * MatrixMinor.determinant();
        }
    }
    return determinantResult;
}

S21Matrix S21Matrix::inverse_matrix() {
    double determinantCheck = determinant();
    if (fabs(determinantCheck) < 1E-7 || std::isnan(determinantCheck)) {
        throw std::out_of_range("Incorrect input, matrices should have the same size");
    }
    S21Matrix matrixCalcComplements = calc_complements();
    S21Matrix matrixTranspose = matrixCalcComplements.transpose();
    matrixTranspose.mul_number(1.0 / determinantCheck);
    return matrixTranspose;
}

void S21Matrix::fill_matrix() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = i + j;
        }
    }
}

void S21Matrix::init_matrix() {
    _matrix = new double*[_rows];
    for (int i = 0; i < _rows; i++) {
        _matrix[i] = new double[_cols]();
    }
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
    S21Matrix resultMatrix(*this);
    resultMatrix.sum_matrix(other);
    return resultMatrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
    S21Matrix resultMatrix(*this);
    resultMatrix.sub_matrix(other);
    return resultMatrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
    S21Matrix resultMatrix(*this);
    resultMatrix.mul_matrix(other);
    return resultMatrix;
}

bool S21Matrix::operator==(const S21Matrix& other) { return eq_matrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (this != &other) {
        delate_matrix();
        _rows = other._rows;
        _cols = other._cols;
        init_matrix();
    }
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = other._matrix[i][j];
        }
    }
    return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
    sum_matrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
    sub_matrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
    mul_matrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double value) {
    mul_number(value);
    return *this;
}

double& S21Matrix::operator()(int row, int col) {
    if (row >= _rows || col >= _cols || row < 0 || col < 0) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return _matrix[row][col];
}

S21Matrix operator*(const double value, const S21Matrix& other) {
    if (std::isnan(value) || std::isinf(value)) {
        throw std::out_of_range("Incorrect input, number should have correct value");
    }
    S21Matrix resultMatrix(other.getRows(), other.getCols());
    resultMatrix = other;
    resultMatrix.mul_number(value);
    return resultMatrix;
}

S21Matrix operator*(const S21Matrix& other, const double value) {
    if (std::isnan(value) || std::isinf(value)) {
        throw std::out_of_range("Incorrect input, number should have correct value");
    }
    S21Matrix resultMatrix(other.getRows(), other.getCols());
    resultMatrix = other;
    resultMatrix.mul_number(value);
    return resultMatrix;
}

void S21Matrix::delate_matrix() {
    for (int i = 0; i < _rows; i++) {
        delete[] _matrix[i];
    }
    delete[] _matrix;
}

}  // namespace s21
