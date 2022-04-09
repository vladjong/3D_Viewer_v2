#pragma once

#include <fstream>
#include <string>

#include "types.h"

namespace s21 {
constexpr char SETTING_FILE[] = USER_APP "setting/setting.conf";

struct SettingData {
    std::string edgeColor;
    std::string edgeThickness;
    std::string edgeType;
    std::string verticesColor;
    std::string verticesSize;
    std::string verticesShape;
    std::string projectionType;
    std::string backgroundColor;
    std::string calculateType;
};

class SettingModel {
 private:
    SettingData* _data;

 public:
    SettingModel() : _data(new SettingData) {}
    ~SettingModel() { delete _data; }
    void readFileSetting();
    void writeFileSetting();
    SettingData* getSettingData() { return _data; }

 private:
    SettingModel(const SettingModel&) = delete;
    SettingModel& operator=(SettingModel&) = delete;
};

}  // namespace s21
