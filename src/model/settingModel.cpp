#include "settingModel.h"

namespace s21 {

std::string fillData(std::string data) {
    std::string value;
    size_t index = data.find("=") + 1;
    return value = data.substr(index);
}

void SettingModel::readFileSetting() {
    std::ifstream fout(SETTING_FILE);
    if (!fout) {
        throw std::invalid_argument("NO SUCH FILE!");
    }
    while (fout) {
        std::string line;
        getline(fout, line);
        if (line.find("EDGE_COLOR") != std::string::npos) {
            _data->edgeColor = fillData(line);
        } else if (line.find("EDGE_THICKNESS") != std::string::npos) {
            _data->edgeThickness = fillData(line);
        } else if (line.find("EDGE_TYPE") != std::string::npos) {
            _data->edgeType = fillData(line);
        } else if (line.find("VERTICES_COLOR") != std::string::npos) {
            _data->verticesColor = fillData(line);
        } else if (line.find("VERTICES_SIZE") != std::string::npos) {
            _data->verticesSize = fillData(line);
        } else if (line.find("VERTICES_SHAPE") != std::string::npos) {
            _data->verticesShape = fillData(line);
        } else if (line.find("PROJECTION_TYPE") != std::string::npos) {
            _data->projectionType = fillData(line);
        } else if (line.find("BACKGROUND_COLOR") != std::string::npos) {
            _data->backgroundColor = fillData(line);
        } else if (line.find("CALCULATE_TYPE") != std::string::npos) {
            _data->calculateType = fillData(line);
        }
    }
}

void SettingModel::writeFileSetting() {
    std::ofstream out(SETTING_FILE);
    if (!out) {
        throw std::invalid_argument("NO SUCH FILE!");
    }
    out << "EDGE_COLOR=" + _data->edgeColor << std::endl;
    out << "EDGE_THICKNESS=" + _data->edgeThickness << std::endl;
    out << "EDGE_TYPE=" + _data->edgeType << std::endl;
    out << "VERTICES_COLOR=" + _data->verticesColor << std::endl;
    out << "VERTICES_SIZE=" + _data->verticesSize << std::endl;
    out << "VERTICES_SHAPE=" + _data->verticesShape << std::endl;
    out << "PROJECTION_TYPE=" + _data->projectionType << std::endl;
    out << "BACKGROUND_COLOR=" + _data->backgroundColor << std::endl;
    out << "CALCULATE_TYPE=" + _data->calculateType << std::endl;
}

}  // namespace s21
