#include "dataStorage.h"

namespace s21 {

inline double get_vertex_from_string(const std::string &line, size_t &pos) {
    double v_value = 0;
    size_t sub_pos = 0;
    v_value = std::stod(line.substr(pos), &sub_pos);
    pos += sub_pos;
    return v_value;
}

inline size_t get_edge_from_string(const std::string &line, size_t &pos) {
    size_t edge = 0;
    size_t sub_pos = 0;
    edge = std::stoi(line.substr(pos), &sub_pos);
    pos += sub_pos;
    return edge - 1;  // decrement for match the vertex index
}

inline void parser(Figure &myfigure, const std::string &line) {
    size_t pos = 1;
    if (line[0] == 'v' && line[1] == ' ') {
        double x, y, z;
        x = get_vertex_from_string(line, pos);
        if (line[pos] != ' ') throw std::invalid_argument("Wrong file format!");
        y = get_vertex_from_string(line, pos);
        if (line[pos] != ' ') throw std::invalid_argument("Wrong file format!");
        z = get_vertex_from_string(line, pos);
        myfigure.pushVertex(x, y, z);
        ExtremeXYZ &extreme = myfigure.getExtremeXYZ();
        extreme.x_min = std::min(x, extreme.x_min);
        extreme.x_max = std::max(x, extreme.x_max);
        extreme.y_min = std::min(y, extreme.y_min);
        extreme.y_max = std::max(y, extreme.y_max);
        extreme.z_min = std::min(z, extreme.z_min);
        extreme.z_max = std::max(z, extreme.z_max);
    } else if (line[0] == 'f' && line[1] == ' ') {
        size_t first = get_edge_from_string(line, pos);
        size_t last = first;
        while (pos < line.length()) {
            if (line[pos] != ' ') {
                pos++;
                continue;
            }
            size_t current = get_edge_from_string(line, pos);
            if ((size_t)current >= myfigure.getVertices().size()) {
                throw std::invalid_argument("Wrong file format!");
            }
            myfigure.pushEdge(last, current);
            last = current;
        }
        myfigure.pushEdge(last, first);
    }
}

void Figure::readFile(std::string filename) {
    _edges.clear();
    _vertices.clear();
    std::ifstream fout(filename);
    if (!fout) {
        throw std::invalid_argument("Please, choose existing file!");
    }
    _extreme.x_min = INFINITY;
    _extreme.x_max = -INFINITY;
    _extreme.y_min = INFINITY;
    _extreme.y_max = -INFINITY;
    _extreme.z_min = INFINITY;
    _extreme.z_max = -INFINITY;
    while (fout) {
        std::string line;
        getline(fout, line);
        if (line.length() > 2) parser(*this, line);
    }
    _init_vertices = _vertices;
}

}  // namespace s21
