#include "viewerView.h"

#include "../ui/ui_viewerView.h"

namespace s21 {

MainWindow::MainWindow(Facade *facade, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), _facade(facade), _timer(new QTimer) {
    ui->setupUi(this);
    ui->widget->setFacade(_facade);
    ui->widget->setSliders(ui->slider_translate_x, ui->slider_translate_y, ui->slider_rotate_x,
                           ui->slider_rotate_y, ui->slider_scale);
    initUi();
    _settingView = new SettingView(_facade);
    connect(_timer, SIGNAL(timeout()), this, SLOT(onTimerOverflow()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete (_timer);
}

void MainWindow::on_btn_choose_file_clicked() {
    try {
        QString fileName =
            QFileDialog::getOpenFileName(this, ("Open the file"),  QDir::homePath(), "*.obj");
        _facade->readFile(fileName.toStdString());
        setModelInfo(fileName);
        initUi();
        ui->widget->initModelData();
        ui->widget->update();
    } catch (std::invalid_argument &ex) {
        showMessageBox(ex.what());
    }
}

void MainWindow::on_btn_settings_clicked() {
    _settingView->setWindowTitle("Setting");
    _settingView->setModal(true);
    _settingView->show();
    ui->widget->update();
}

// SLIDER MOVED EVENTS

void MainWindow::on_slider_rotate_x_sliderMoved(int position) {
    ui->widget->getData()->xRot = position;
    ui->widget->getData()->xRotMem = position;
    ui->widget->update();
}

void MainWindow::on_slider_rotate_y_sliderMoved(int position) {
    ui->widget->getData()->yRot = position;
    ui->widget->getData()->yRotMem = position;
    ui->widget->update();
}

void MainWindow::on_slider_rotate_z_sliderMoved(int position) {
    ui->widget->getData()->zRot = position;
    ui->widget->update();
}

void MainWindow::on_slider_translate_x_sliderMoved(int position) {
    ui->widget->getData()->xTrans =
        position * 0.0032 * (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min);
    ui->widget->getData()->xTransMem = ui->widget->getData()->xTrans;
    ui->widget->update();
}

void MainWindow::on_slider_translate_y_sliderMoved(int position) {
    ui->widget->getData()->yTrans =
        position * 0.0032 * (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min);
    ui->widget->getData()->yTransMem = ui->widget->getData()->yTrans;
    ui->widget->update();
}

void MainWindow::on_slider_translate_z_sliderMoved(int position) {
    ui->widget->getData()->zTrans =
        position * 0.0032 * (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min);
    ui->widget->update();
}

void MainWindow::on_slider_scale_sliderMoved(int position) {
    ui->widget->getData()->scale = pow(10, position / 100.0) / 100;
    ui->widget->update();
}

// SLIDER PRESSED EVENTS

void MainWindow::on_slider_rotate_x_sliderPressed() {
    int position = ui->slider_rotate_x->value();
    ui->widget->getData()->xRot = position;
    ui->widget->getData()->xRotMem = position;
    ui->widget->update();
}

void MainWindow::on_slider_rotate_y_sliderPressed() {
    int position = ui->slider_rotate_y->value();
    ui->widget->getData()->yRot = position;
    ui->widget->getData()->yRotMem = position;
    ui->widget->update();
}

void MainWindow::on_slider_rotate_z_sliderPressed() {
    int position = ui->slider_rotate_z->value();
    ui->widget->getData()->zRot = position;
    ui->widget->update();
}

void MainWindow::on_slider_translate_x_sliderPressed() {
    int position = ui->slider_translate_x->value();
    ui->widget->getData()->xTrans =
        position * 0.0032 * (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min);
    ui->widget->getData()->xTransMem = ui->widget->getData()->xTrans;
    ui->widget->update();
}

void MainWindow::on_slider_translate_y_sliderPressed() {
    int position = ui->slider_translate_y->value();
    ui->widget->getData()->yTrans =
        position * 0.0032 * (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min);
    ui->widget->getData()->yTransMem = ui->widget->getData()->yTrans;
    ui->widget->update();
}

void MainWindow::on_slider_translate_z_sliderPressed() {
    int position = ui->slider_translate_z->value();
    ui->widget->getData()->zTrans =
        position * 0.0032 * (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min);
    ui->widget->update();
}

void MainWindow::on_slider_scale_sliderPressed() {
    int position = ui->slider_scale->value();
    ui->widget->getData()->scale = pow(10, position / 100.0) / 100;
    ui->widget->update();
}

/* need to add a function */
void MainWindow::setModelInfo(QString fileName) {
    qsizetype n = fileName.lastIndexOf('/') + 1;
    fileName = fileName.right(fileName.size() - n);
    ui->le_model->setText(fileName);
    ui->label_model_set->setText(fileName);
    ui->label_edge_set->setText(QString::number(_facade->getEdges().size()));
    ui->label_vertex_set->setText(QString::number(_facade->getVertices().size()));
}

void MainWindow::initUi() {
    // Line edit set
    ui->le_translate_x->setText("0");
    ui->le_translate_y->setText("0");
    ui->le_translate_z->setText("0");
    ui->le_rotate_x->setText("0");
    ui->le_rotate_y->setText("0");
    ui->le_rotate_z->setText("0");
    ui->le_scale->setText("100");
    // Slider position set
    ui->slider_translate_x->setValue(0);
    ui->slider_translate_y->setValue(0);
    ui->slider_translate_z->setValue(0);
    ui->slider_rotate_x->setValue(0);
    ui->slider_rotate_y->setValue(0);
    ui->slider_rotate_z->setValue(0);
    ui->slider_scale->setValue(200);
}

void MainWindow::showMessageBox(QString message) {
    QMessageBox msg_box(this);
    msg_box.setStyleSheet("background-color: #1A1D21;");
    QPushButton *btn = msg_box.addButton("I won't do this anymore", QMessageBox::ActionRole);
    btn->setStyleSheet(QString::fromUtf8(BUTTON_STYLE) + QString::fromUtf8("QPushButton {\n"
                                                                           "   padding: 5px 10px;"
                                                                           "}"));
    msg_box.setText(message);
    msg_box.exec();
}

// SCREENSHOT

void MainWindow::on_btn_screenshot_clicked() {
    QImage img = ui->widget->grabFramebuffer();
    QString filename = ui->le_model->text();
    if (!filename.isEmpty()) {
        filename.resize(filename.size() - 4);
        img.save(USER_APP "screenshots/" + filename + ".jpeg", "JPEG");
        img.save(USER_APP "screenshots/" + filename + ".bmp", "BMP");
    }
}

// SCREENCAST

void MainWindow::on_btn_screencast_clicked() {
    _cntr_timer = 0;
    _timer->start(100);
}

void MainWindow::onTimerOverflow() {
    if (_cntr_timer < 50) {
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << _cntr_timer;
        QString filename = QString::fromStdString(ss.str());
        QImage img = ui->widget->grabFramebuffer();
        img.save(USER_APP "screencasts/" + filename + ".png", "PNG", 0);
        _cntr_timer++;
    } else {
        _timer->stop();
        _cntr_timer = 0;
        system("convert -delay 10 -loop 0 screencasts/*.png screencasts/screencast.gif");
        system("rm -f screencasts/*.png");
    }
}

// CLICKED BUTTONS

void normalize_value(float &value, float min, float max) {
    if (value < min)
        value = min;
    else if (value > max)
        value = max;
}

void MainWindow::on_btn_translate_clicked() {
    bool ok_x, ok_y, ok_z;
    float koef = 0.0032 * (_facade->getExtremeXYZ().z_max - _facade->getExtremeXYZ().z_min);
    float res_x = ui->le_translate_x->text().toFloat(&ok_x);
    float res_y = ui->le_translate_y->text().toFloat(&ok_y);
    float res_z = ui->le_translate_z->text().toFloat(&ok_z);
    if (ok_x && ok_y && ok_z) {
        ui->widget->getData()->xTrans = res_x * koef;
        ui->widget->getData()->xTransMem = res_x * koef;
        ui->slider_translate_x->setValue(res_x);
        ui->widget->getData()->yTrans = res_y * koef;
        ui->widget->getData()->yTransMem = res_y * koef;
        ui->slider_translate_y->setValue(res_y);
        ui->widget->getData()->zTrans = res_z * koef;
        ui->slider_translate_z->setValue(res_z);
        ui->widget->update();
    } else {
        showMessageBox("Enter valid data to translate the model");
    }
}

void MainWindow::on_btn_rotate_clicked() {
    bool ok_x, ok_y, ok_z;
    float res_x = ui->le_rotate_x->text().toFloat(&ok_x);
    float res_y = ui->le_rotate_y->text().toFloat(&ok_y);
    float res_z = ui->le_rotate_z->text().toFloat(&ok_z);
    normalize_value(res_x, 0.f, 360.f);
    normalize_value(res_y, 0.f, 360.f);
    normalize_value(res_z, 0.f, 360.f);
    if (ok_x && ok_y && ok_z) {
        ui->widget->getData()->xRot = res_x;
        ui->widget->getData()->xRotMem = res_x;
        ui->slider_rotate_x->setValue(res_x);
        ui->widget->getData()->yRot = res_y;
        ui->widget->getData()->yRotMem = res_y;
        ui->slider_rotate_y->setValue(res_y);
        ui->widget->getData()->zRot = res_z;
        ui->slider_rotate_z->setValue(res_z);
        ui->widget->update();
    } else {
        showMessageBox("Enter valid data to rotate the model");
    }
}

void MainWindow::on_btn_scale_clicked() {
    bool ok;
    float res = ui->le_scale->text().toFloat(&ok);
    normalize_value(res, 1.f, 10000.f);
    if (ok) {
        ui->widget->getData()->scale = res / 100.0;
        ui->slider_scale->setValue(100 * log10(res));
        ui->widget->update();
    } else {
        showMessageBox("Enter valid data to scale the model");
    }
}

// SLIDER VALUE CHANGED

void MainWindow::on_slider_rotate_x_valueChanged(int position) {
    ui->le_rotate_x->setText(QString::number(position));
}

void MainWindow::on_slider_rotate_y_valueChanged(int position) {
    ui->le_rotate_y->setText(QString::number(position));
}

void MainWindow::on_slider_rotate_z_valueChanged(int position) {
    ui->le_rotate_z->setText(QString::number(position));
}

void MainWindow::on_slider_translate_x_valueChanged(int position) {
    ui->le_translate_x->setText(QString::number(position));
}

void MainWindow::on_slider_translate_y_valueChanged(int position) {
    ui->le_translate_y->setText(QString::number(position));
}

void MainWindow::on_slider_translate_z_valueChanged(int position) {
    ui->le_translate_z->setText(QString::number(position));
}

void MainWindow::on_slider_scale_valueChanged(int position) {
    ui->le_scale->setText(QString::number(pow(10, position / 100.0)));
}

}  // namespace s21
