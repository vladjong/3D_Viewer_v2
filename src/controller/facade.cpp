#include "facade.h"

namespace s21 {

// FACADE

Facade::Facade(Figure *figure) : _figure(figure), _settingModel(new SettingModel) {}

Facade::~Facade() {
    delete _settingModel;
}

void Facade::moveFigure(double x, double y, double z) {
    _figure->transform(TransformMatrixBuilder::CreateMoveMatrix(x, y, z));
}

void Facade::rotateFigure(double x, double y, double z) {
    _figure->transform(TransformMatrixBuilder::CreateRotationMatrix(x, y, z));
}

void Facade::scaleFigure(double x, double y, double z) {
    _figure->transform(TransformMatrixBuilder::CreateScaleMatrix(x, y, z));
}

void Facade::readFile(std::string filename) { _figure->readFile(filename); }

}  // namespace s21
