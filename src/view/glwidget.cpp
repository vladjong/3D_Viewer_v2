#include "glwidget.h"

namespace s21 {

// MODEL DATA
ModelData::ModelData() { initModelData(); }

void ModelData::initModelData() {
    xRot = 0;
    yRot = 0;
    zRot = 0;
    xRotMem = 0;
    yRotMem = 0;
    xTrans = 0;
    yTrans = 0;
    zTrans = 0;
    xTransMem = 0;
    yTransMem = 0;
    scale = 1.0;
}

// RENDER GPU
void RenderGPU::renderModel(Facade *facade, ModelData *data) {
    glTranslatef(data->xTrans, data->yTrans,
                 data->zTrans + (facade->getExtremeXYZ().z_max - facade->getExtremeXYZ().z_min) * -2);

    glScalef(data->scale, data->scale, data->scale);
    glRotatef(data->xRot, 1, 0, 0);
    glRotatef(data->yRot, 0, 1, 0);
    glRotatef(data->zRot, 0, 0, 1);
}

void RenderCPU::renderModel(Facade *facade, ModelData *data) {
    Q_UNUSED(data);
    glTranslatef(0, 0, (facade->getExtremeXYZ().z_max - facade->getExtremeXYZ().z_min) * -2);
    facade->moveFigure(data->xTrans, data->yTrans, data->zTrans);
    facade->scaleFigure(data->scale, data->scale, data->scale);
    facade->rotateFigure(data->xRot, data->yRot, data->zRot);
}

// GLWIDGET
GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent), _data(new ModelData), _sliders(new Sliders) {
    _render = nullptr;
    _facade = nullptr;
}

GLWidget::~GLWidget() {
    delete _data;
    delete _sliders;
    delete _render;
}

void GLWidget::initModelData() { _data->initModelData(); }

ModelData *GLWidget::getData() { return _data; }

void GLWidget::setFacade(Facade *facade) { _facade = facade; }

void GLWidget::setSliders(QSlider *translate_x, QSlider *translate_y, QSlider *rotate_x, QSlider *rotate_y,
                          QSlider *scale) {
    _sliders->translate_x = translate_x;
    _sliders->translate_y = translate_y;
    _sliders->rotate_x = rotate_x;
    _sliders->rotate_y = rotate_y;
    _sliders->scale = scale;
}

void GLWidget::mousePressEvent(QMouseEvent *mo) {
    _data->mBtn = mo->button();
    _data->mPos = mo->pos();
}

inline float degreesNormilize(float deg) {
    if (deg < 0) {
        deg += 360;
    }
    deg = fmod(deg, 360.0);
    return deg;
}

void GLWidget::mouseMoveEvent(QMouseEvent *mo) {
    if (dynamic_cast<RenderGPU *>(_render)) {
        if (_data->mBtn == Qt::RightButton) {
            _data->xRot = 1 / M_PI * (mo->pos().y() - _data->mPos.y()) + _data->xRotMem;
            _data->xRot = degreesNormilize(_data->xRot);
            _data->yRot = 1 / M_PI * (mo->pos().x() - _data->mPos.x()) + _data->yRotMem;
            _data->yRot = degreesNormilize(_data->yRot);
            _sliders->rotate_x->setValue(static_cast<int>(_data->xRot));
            _sliders->rotate_y->setValue(static_cast<int>(_data->yRot));
        } else if (_data->mBtn == Qt::LeftButton) {
            _data->xTrans = 0.0032 * (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min) *
                                (mo->pos().x() - _data->mPos.x()) +
                            _data->xTransMem;
            _data->yTrans = -0.0032 * (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min) *
                                (mo->pos().y() - _data->mPos.y()) +
                            _data->yTransMem;
            _sliders->translate_x->setValue(static_cast<int>(
                _data->xTrans / 0.0032 / (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min)));
            _sliders->translate_y->setValue(static_cast<int>(
                _data->yTrans / 0.0032 / (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min)));
        }
        update();
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *mo) {
    Q_UNUSED(mo);
    _data->xRotMem = _data->xRot;
    _data->yRotMem = _data->yRot;
    _data->xTransMem = _data->xTrans;
    _data->yTransMem = _data->yTrans;
}

void GLWidget::wheelEvent(QWheelEvent *event) {
    if (dynamic_cast<RenderGPU *>(_render)) {
        QPoint deg = event->angleDelta() / 8;
        if (deg.y() > 0) {
            _data->scale *= 1.1;
        } else {
            _data->scale /= 1.1;
        }
        _sliders->scale->setValue(static_cast<int>(100 * log10(_data->scale * 100)));
        update();
    }
}

inline void GLWidget::viewFigure(bool point) {
    if (point) {
        glBegin(GL_POINTS);
    } else {
        glBegin(GL_LINES);
    }
    for (size_t i = 0; i < _facade->getEdges().size(); i++) {
        _3DPoint begin = _facade->getVertices()[_facade->getEdges()[i].getBegin()].getPosition();
        _3DPoint end = _facade->getVertices()[_facade->getEdges()[i].getEnd()].getPosition();
        glVertex3d(begin.x, begin.y, begin.z);
        glVertex3d(end.x, end.y, end.z);
    }
    glEnd();
}

void GLWidget::initializeGL() {}

void GLWidget::setSettingBase() {
    glLineWidth(std::stof(_facade->getSettingData()->edgeThickness));
    setEdgesType(_facade->getSettingData()->edgeType);
    setProjection(_facade->getSettingData()->projectionType);
    setColorBackgroung(_facade->getSettingData()->backgroundColor);
    setCalculateType(_facade->getSettingData()->calculateType);
}

void GLWidget::setSettingView() {
    glPointSize(std::stof(_facade->getSettingData()->verticesSize) * 2);
    setVerticesShape(_facade->getSettingData()->verticesShape);
    setColorEdges(_facade->getSettingData()->edgeColor);
}

void GLWidget::setCalculateType(std::string type) {
    if (type == "GPU") {
        _render = new RenderGPU;
    } else if (type == "CPU") {
        _render = new RenderCPU;
    }
}

void GLWidget::setColorBackgroung(std::string color) {
    if (color == "black") {
        glClearColor(0.1, 0.11, 0.13, 0);
    } else if (color == "dracula") {
        glClearColor(0.16, 0.16, 0.21, 0);
    } else if (color == "brown") {
        glClearColor(0.48, 0.41, 0.40, 0);
    }
}

void GLWidget::setEdgesType(std::string type) {
    if (type == "solid") {
        glDisable(GL_LINE_STIPPLE);
    } else if (type == "dotted") {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x0101);
    }
}

void GLWidget::setColorEdges(std::string color) {
    if (color == "white") {
        glColor3f(0.99, 1, 0.95);
    } else if (color == "blue") {
        glColor3f(0, 0.35, 0.61);
    } else if (color == "green") {
        glColor3f(0.57, 0.68, 0.46);
    } else if (color == "yellow") {
        glColor3f(0.8, 0.68, 0.07);
    } else if (color == "red") {
        glColor3f(0.58, 0, 0);
    }
}

void GLWidget::setVerticesShape(std::string shape) {
    if (shape == "circle") {
        glEnable(GL_POINT_SMOOTH);
        setVerticesColor(_facade->getSettingData()->verticesColor);
        viewFigure(true);
    } else if (shape == "square") {
        glDisable(GL_POINT_SMOOTH);
        setVerticesColor(_facade->getSettingData()->verticesColor);
        viewFigure(true);
    }
}

void GLWidget::setVerticesColor(std::string color) {
    if (color == "white") {
        glColor3d(0.99, 1, 0.95);
    } else if (color == "blue") {
        glColor3d(0, 0.35, 0.61);
    } else if (color == "green") {
        glColor3d(0.57, 0.68, 0.46);
    } else if (color == "yellow") {
        glColor3d(0.8, 0.68, 0.07);
    } else if (color == "red") {
        glColor3d(0.58, 0, 0);
    }
}

void GLWidget::setProjection(std::string projection) {
    if (projection == "central") {
        gluPerspective(100, 1.2, 0.1, 1000.0);
    } else if (projection == "parallel") {
        glOrtho(_facade->getExtremeXYZ().x_min * 2, _facade->getExtremeXYZ().x_max * 2,
                _facade->getExtremeXYZ().y_min * 2, _facade->getExtremeXYZ().y_max * 2, 0.1, 1000.0);
    }
}

void GLWidget::paintGL() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    setSettingBase();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    _render->renderModel(_facade, _data);
    setSettingView();
    viewFigure(false);
}

void GLWidget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

}  // namespace s21
