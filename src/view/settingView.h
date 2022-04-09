#pragma once

#include <QtWidgets/QDialog>

#include "../controller/facade.h"

namespace Ui {
class SettingView;
}

namespace s21 {
class SettingView : public QDialog {
    Q_OBJECT

 public:
    explicit SettingView(Facade *facade, QWidget *parent = nullptr);
    ~SettingView();

 private:
    Ui::SettingView *ui;
    Facade *_facade;
    size_t _thickness;
    size_t _size;

    void fillSettingFile();
    void fillSettingDefault();
    void fillSettingFromFile();

 private slots:
    void on_applyButton_clicked();
    void on_cancelButton_clicked();
    void on_edgeMinusButton_clicked();
    void on_edgePlusButton_clicked();
    void on_verticesMinusButton_clicked();
    void on_verticesPlusButton_clicked();
    void on_resetButton_clicked();
};

}  // namespace s21
