#include <gtest/gtest.h>

#include <vector>

#include "model/dataStorage.h"
#include "controller/facade.h"

using s21::Facade;
using s21::Figure;

TEST(readModel, vertices) {
    std::vector<std::vector<double>> result{{0, 1, 1}, {0, 0, 1}, {1, 0, 1}, {1, 1, 1},
                                            {0, 1, 0}, {0, 0, 0}, {1, 0, 0}, {1, 1, 0}};
    Figure _figure;
    Facade _facade(&_figure);
    _facade.readFile("objects/cub.obj");
    for (size_t i = 0; i < _facade.getVertices().size(); i++) {
        ASSERT_EQ(result[i][0], _figure.getVertices()[i].getPosition().x);
        ASSERT_EQ(result[i][1], _figure.getVertices()[i].getPosition().y);
        ASSERT_EQ(result[i][2], _figure.getVertices()[i].getPosition().z);
    }
}

TEST(readModel, edges) {
    std::vector<std::vector<double>> result{{0, 1}, {1, 2}, {2, 3}, {3, 0}, {7, 6}, {6, 5}, {5, 4}, {4, 7},
                                            {3, 2}, {2, 6}, {6, 7}, {7, 3}, {4, 0}, {0, 3}, {3, 7}, {7, 4},
                                            {4, 5}, {5, 1}, {1, 0}, {0, 4}, {1, 5}, {5, 6}, {6, 2}, {2, 1}};
    Figure _figure;
    Facade _facade(&_figure);
    _facade.readFile("objects/cub.obj");
    for (size_t i = 0; i < _facade.getEdges().size(); i++) {
        ASSERT_EQ(result[i][0], _figure.getEdges()[i].getBegin());
        ASSERT_EQ(result[i][1], _figure.getEdges()[i].getEnd());
    }
}

TEST(affineTransform, moveFigure) {
    std::vector<std::vector<double>> result{{0.1, 1.3, 0},  {0.1, 0.3, 0},  {1.1, 0.3, 0},  {1.1, 1.3, 0},
                                            {0.1, 1.3, -1}, {0.1, 0.3, -1}, {1.1, 0.3, -1}, {1.1, 1.3, -1}};
    Figure _figure;
    Facade _facade(&_figure);
    _facade.readFile("objects/cub.obj");
    _facade.moveFigure(0.1, 0.3, -1);
    for (size_t i = 0; i < _figure.getVertices().size(); i++) {
        ASSERT_EQ(result[i][0], _figure.getVertices()[i].getPosition().x);
        ASSERT_EQ(result[i][1], _figure.getVertices()[i].getPosition().y);
        ASSERT_EQ(result[i][2], _figure.getVertices()[i].getPosition().z);
    }
}

TEST(affineTransform, rotateFigure) {
    std::vector<std::vector<double>> result{
        {0.194039, 1.378, -0.251922},     {0.368384, 0.769256, 0.522052},
        {1.28156, 0.575154, 0.163684},    {1.10722, 1.1839, -0.61029},
        {-0.174345, 0.608744, -0.773973}, {0.00000000, 0.00000000, 0.00000000},
        {0.913179, -0.194102, -0.358368}, {0.738834, 0.414642, -1.13234}};
    Figure _figure;
    Facade _facade(&_figure);
    _facade.readFile("objects/cub.obj");
    _facade.rotateFigure(56.0, 21.0, 12.0);
    for (size_t i = 0; i < _figure.getVertices().size(); i++) {
        ASSERT_NEAR(result[i][0], _figure.getVertices()[i].getPosition().x, 3);
        ASSERT_NEAR(result[i][1], _figure.getVertices()[i].getPosition().y, 3);
        ASSERT_NEAR(result[i][2], _figure.getVertices()[i].getPosition().z, 3);
    }
}

TEST(affineTransform, scaleFigure) {
    std::vector<std::vector<double>> result{{0, 2, 2}, {0, 0, 2}, {2, 0, 2}, {2, 2, 2},
                                            {0, 2, 0}, {0, 0, 0}, {2, 0, 0}, {2, 2, 0}};
    Figure _figure;
    Facade _facade(&_figure);
    _facade.readFile("objects/cub.obj");
    _facade.scaleFigure(2, 2, 2);
    for (size_t i = 0; i < _figure.getVertices().size(); i++) {
        ASSERT_NEAR(result[i][0], _figure.getVertices()[i].getPosition().x, 3);
        ASSERT_NEAR(result[i][1], _figure.getVertices()[i].getPosition().y, 3);
        ASSERT_NEAR(result[i][2], _figure.getVertices()[i].getPosition().z, 3);
    }
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
