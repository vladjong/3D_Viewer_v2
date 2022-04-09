#pragma once

#include "s21_matrix_oop.h"
#include "types.h"

namespace s21 {
class TransformMatrix {
 public:
    enum class Type { MOVE, SCALE, ROTATE };

 private:
    S21Matrix _matrix;
    Type _type;
    S21Matrix transformPointFromMatrix(const _3DPoint &init_point);

 public:
    explicit TransformMatrix(Type type) : _type(type) {}
    void transformPoint(_3DPoint &point, const _3DPoint &init_point);
    double &operator()(int row, int col);
};

class TransformMatrixBuilder {
 public:
    static TransformMatrix CreateRotationMatrix(double x, double y, double z);
    static TransformMatrix CreateMoveMatrix(double x, double y, double z);
    static TransformMatrix CreateScaleMatrix(double x, double y, double z);
};

}  // namespace s21
