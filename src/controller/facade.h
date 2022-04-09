#pragma once

#include <string>

#include "../model/dataStorage.h"
#include "../model/settingModel.h"

namespace s21 {

class Facade {
 private:
    Figure* _figure;
    SettingModel* _settingModel;

 public:
    explicit Facade(Figure*);
    ~Facade();
    void moveFigure(double x, double y, double z);
    void rotateFigure(double x, double y, double z);
    void scaleFigure(double x, double y, double z);

    void readFile(std::string filename);
    std::vector<Edge>& getEdges() { return _figure->getEdges(); }
    std::vector<Vertex>& getVertices() { return _figure->getVertices(); }
    ExtremeXYZ& getExtremeXYZ() { return _figure->getExtremeXYZ(); }
    // SETTING
    void readFileSetting() { _settingModel->readFileSetting(); }
    void writeFileSetting() { _settingModel->writeFileSetting(); }
    SettingData* getSettingData() { return _settingModel->getSettingData(); }

 private:
    Facade(const Facade&) = delete;
    Facade& operator=(Facade&) = delete;
};

}  // namespace s21
