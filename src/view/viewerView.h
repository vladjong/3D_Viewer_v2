#pragma once

#include <QtCore/QThread>
#include <QtCore/QTimer>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <sstream>

#include "../controller/facade.h"
#include "glwidget.h"
#include "settingView.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(Facade *facade, QWidget *parent = nullptr);
    ~MainWindow();

 private slots:
    void on_btn_choose_file_clicked();
    void on_btn_settings_clicked();
    void on_btn_screenshot_clicked();
    void on_btn_screencast_clicked();
    void on_btn_translate_clicked();
    void on_btn_rotate_clicked();
    void on_btn_scale_clicked();

    // Slider moved event
    void on_slider_rotate_x_sliderMoved(int position);
    void on_slider_rotate_y_sliderMoved(int position);
    void on_slider_rotate_z_sliderMoved(int position);
    void on_slider_translate_x_sliderMoved(int position);
    void on_slider_translate_y_sliderMoved(int position);
    void on_slider_translate_z_sliderMoved(int position);
    void on_slider_scale_sliderMoved(int position);
    // Slider pressed event
    void on_slider_rotate_x_sliderPressed();
    void on_slider_rotate_y_sliderPressed();
    void on_slider_rotate_z_sliderPressed();
    void on_slider_translate_x_sliderPressed();
    void on_slider_translate_y_sliderPressed();
    void on_slider_translate_z_sliderPressed();
    void on_slider_scale_sliderPressed();
    // Slider valuechanged event
    void on_slider_rotate_x_valueChanged(int position);
    void on_slider_rotate_y_valueChanged(int position);
    void on_slider_rotate_z_valueChanged(int position);
    void on_slider_translate_x_valueChanged(int position);
    void on_slider_translate_y_valueChanged(int position);
    void on_slider_translate_z_valueChanged(int position);
    void on_slider_scale_valueChanged(int position);
    // Timer
    void onTimerOverflow();

 private:
    Ui::MainWindow *ui;
    Facade *_facade;
    SettingView *_settingView;
    // Timers
    QTimer *_timer;
    int _cntr_timer;

    void setModelInfo(QString fileName);
    void initUi();
    void showMessageBox(QString message);
};

}  // namespace s21
