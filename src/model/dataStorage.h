#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "transformMatrix.h"

namespace s21 {
struct ExtremeXYZ {
    double x_min, x_max, y_min, y_max, z_min, z_max;
};

class Vertex {
 private:
    _3DPoint _position;

 public:
    Vertex(double _x, double _y, double _z);
    _3DPoint& getPosition();
};

class Edge {
 private:
    size_t _begin;
    size_t _end;

 public:
    Edge(size_t begin, size_t end);
    size_t getBegin();
    size_t getEnd();
};

class Figure {
 private:
    std::vector<Vertex> _vertices, _init_vertices;
    std::vector<Edge> _edges;
    ExtremeXYZ _extreme;

 public:
    Figure() : _vertices(), _init_vertices(), _edges(), _extreme() {}
    std::vector<Vertex>& getVertices();
    std::vector<Edge>& getEdges();
    ExtremeXYZ& getExtremeXYZ();
    void readFile(std::string name);
    void transform(TransformMatrix);
    void pushVertex(double x, double y, double z);
    void pushEdge(size_t begin, size_t end);
};

}  // namespace s21
