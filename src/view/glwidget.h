#pragma once

#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>

#include <QtGui/QMouseEvent>
#include <QtGui/QWheelEvent>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtWidgets/QSlider>

#include "../controller/facade.h"

namespace s21 {

struct ModelData {
    float xRot, yRot, zRot, xRotMem, yRotMem;
    float xTrans, yTrans, zTrans, xTransMem, yTransMem;
    float scale;
    // Mouse events
    QPoint mPos;
    Qt::MouseButton mBtn;
    // Constructor
    ModelData();
    void initModelData();
};

struct Sliders {
    QSlider *translate_x;
    QSlider *translate_y;
    QSlider *rotate_x;
    QSlider *rotate_y;
    QSlider *scale;
};

class RenderInterface {
 public:
    virtual void renderModel(Facade *facade, ModelData *data) = 0;
    virtual ~RenderInterface() {}
};

class RenderGPU : public RenderInterface {
 public:
    void renderModel(Facade *facade, ModelData *data) override;
};

class RenderCPU : public RenderInterface {
 public:
    void renderModel(Facade *facade, ModelData *data) override;
};

class GLWidget : public QOpenGLWidget {
    Q_OBJECT

 private:
    ModelData *_data;
    Facade *_facade;
    RenderInterface *_render;
    Sliders *_sliders;

    void mousePressEvent(QMouseEvent *mo) override;
    void mouseMoveEvent(QMouseEvent *mo) override;
    void mouseReleaseEvent(QMouseEvent *mo) override;
    void wheelEvent(QWheelEvent *event) override;
    void setSettingBase();
    void setSettingView();
    void setColorBackgroung(std::string);
    void setColorEdges(std::string);
    void setEdgesType(std::string);
    void setProjection(std::string);
    void setVerticesShape(std::string);
    void setVerticesColor(std::string);
    void setCalculateType(std::string);

 public:
    explicit GLWidget(QWidget *parent = nullptr);
    ~GLWidget();
    void initModelData();
    void setFacade(Facade *facade);
    void setSliders(QSlider *translate_x, QSlider *translate_y, QSlider *rotate_x, QSlider *rotate_y,
                    QSlider *scale);
    void viewFigure(bool point);
    ModelData *getData();

 protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
};

}  // namespace s21
