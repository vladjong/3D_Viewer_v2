#include "dataStorage.h"

namespace s21 {

// VERTEX METHODS
Vertex::Vertex(double _x, double _y, double _z) {
    _position.x = _x;
    _position.y = _y;
    _position.z = _z;
}

_3DPoint& Vertex::getPosition() { return _position; }

// EDGE METHODS
Edge::Edge(size_t begin, size_t end) : _begin(begin), _end(end) {}

size_t Edge::getBegin() { return _begin; }

size_t Edge::getEnd() { return _end; }
// FIGURE

std::vector<Vertex>& Figure::getVertices() { return _vertices; }

std::vector<Edge>& Figure::getEdges() { return _edges; }

void Figure::transform(TransformMatrix transformMatrix) {
    for (size_t i = 0; i < _vertices.size(); i++) {
        transformMatrix.transformPoint(_vertices[i].getPosition(), _init_vertices[i].getPosition());
    }
}

ExtremeXYZ& Figure::getExtremeXYZ() { return _extreme; }

void Figure::pushVertex(double x, double y, double z) { _vertices.push_back(Vertex(x, y, z)); }

void Figure::pushEdge(size_t begin, size_t end) { _edges.push_back(Edge(begin, end)); }

}  // namespace s21
