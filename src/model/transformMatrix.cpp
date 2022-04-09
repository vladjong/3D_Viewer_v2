#include "transformMatrix.h"

namespace s21 {

// TRANSFORM MATRIX

double& TransformMatrix::operator()(int row, int col) {
    if (row >= 4 || col >= 4 || row < 0 || col < 0) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return _matrix(row, col);
}

S21Matrix TransformMatrix::transformPointFromMatrix(const _3DPoint& points) {
    S21Matrix _matrixPoint(1, 4);
    _matrixPoint(0, 0) = points.x;
    _matrixPoint(0, 1) = points.y;
    _matrixPoint(0, 2) = points.z;
    _matrixPoint(0, 3) = 1;
    return _matrixPoint;
}

void TransformMatrix::transformPoint(_3DPoint& points, const _3DPoint& init_points) {
    S21Matrix _matrixPoint;
    if (_type == Type::MOVE) {
        _matrixPoint = transformPointFromMatrix(init_points);
    } else {
        _matrixPoint = transformPointFromMatrix(points);
    }
    _matrixPoint.mul_matrix(_matrix);
    points.x = _matrixPoint(0, 0);
    points.y = _matrixPoint(0, 1);
    points.z = _matrixPoint(0, 2);
}

// TRANSFORM MATRIX BUILDER

TransformMatrix TransformMatrixBuilder::CreateRotationMatrix(double x, double y, double z) {
    x *= M_PI / 180;
    y *= M_PI / 180;
    z *= M_PI / 180;

    TransformMatrix _transformMatrix(TransformMatrix::Type::ROTATE);
    _transformMatrix(0, 0) = cos(y) * cos(z);
    _transformMatrix(0, 1) = -cos(y) * sin(z);
    _transformMatrix(0, 2) = -sin(y);
    _transformMatrix(1, 0) = -sin(x) * sin(y) * cos(z) + cos(x) * sin(z);
    _transformMatrix(1, 1) = sin(x) * sin(y) * sin(z) + cos(x) * cos(z);
    _transformMatrix(1, 2) = -sin(x) * cos(y);
    _transformMatrix(2, 0) = cos(x) * sin(y) * cos(z) + sin(x) * sin(z);
    _transformMatrix(2, 1) = -cos(x) * sin(y) * sin(z) + sin(x) * cos(z);
    _transformMatrix(2, 2) = cos(x) * cos(y);
    return _transformMatrix;
}

TransformMatrix TransformMatrixBuilder::CreateMoveMatrix(double x, double y, double z) {
    TransformMatrix _transformMatrix(TransformMatrix::Type::MOVE);
    _transformMatrix(0, 0) = 1;
    _transformMatrix(1, 1) = 1;
    _transformMatrix(2, 2) = 1;
    _transformMatrix(3, 3) = 1;
    _transformMatrix(3, 0) = x;
    _transformMatrix(3, 1) = y;
    _transformMatrix(3, 2) = z;
    return _transformMatrix;
}

TransformMatrix TransformMatrixBuilder::CreateScaleMatrix(double x, double y, double z) {
    TransformMatrix _transformMatrix(TransformMatrix::Type::SCALE);
    _transformMatrix(0, 0) = x;
    _transformMatrix(1, 1) = y;
    _transformMatrix(2, 2) = z;
    _transformMatrix(3, 3) = 1;
    return _transformMatrix;
}

}  // namespace s21
