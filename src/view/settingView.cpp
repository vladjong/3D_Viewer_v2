#include "settingView.h"

#include <iostream>

#include "../ui/ui_settingView.h"

namespace s21 {

SettingView::SettingView(Facade *facade, QWidget *parent)
    : QDialog(parent), ui(new Ui::SettingView), _facade(facade) {
    ui->setupUi(this);
    fillSettingFromFile();
    _thickness = ui->edgeLineEdit->text().toUInt();
    _size = ui->verticesLineEdit->text().toUInt();
}

SettingView::~SettingView() { delete ui; }

void SettingView::on_applyButton_clicked() {
    fillSettingFile();
    try {
        _facade->writeFileSetting();
    } catch (std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
    }
    hide();
}

void SettingView::on_cancelButton_clicked() { hide(); }

void SettingView::on_resetButton_clicked() {
    fillSettingDefault();
    try {
        _facade->writeFileSetting();
    } catch (std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
    }
    fillSettingFromFile();
}

void SettingView::fillSettingFromFile() {
    try {
        _facade->readFileSetting();
    } catch (std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
    }
    ui->edgeColorComboBox->setCurrentText(QString::fromStdString(_facade->getSettingData()->edgeColor));
    ui->edgeLineEdit->setText(QString::fromStdString(_facade->getSettingData()->edgeThickness));
    ui->typeComboBox->setCurrentText(QString::fromStdString(_facade->getSettingData()->edgeType));
    ui->verticesColorComboBox->setCurrentText(
        QString::fromStdString(_facade->getSettingData()->verticesColor));
    ui->verticesLineEdit->setText(QString::fromStdString(_facade->getSettingData()->verticesSize));
    ui->verticesShapeComboBox->setCurrentText(
        QString::fromStdString(_facade->getSettingData()->verticesShape));
    ui->projectionTypeComboBox->setCurrentText(
        QString::fromStdString(_facade->getSettingData()->projectionType));
    ui->backgroundColorComboBox->setCurrentText(
        QString::fromStdString(_facade->getSettingData()->backgroundColor));
    ui->calculateTypeComboBox->setCurrentText(
        QString::fromStdString(_facade->getSettingData()->calculateType));
}

void SettingView::fillSettingFile() {
    _facade->getSettingData()->edgeColor = ui->edgeColorComboBox->currentText().toStdString();
    _facade->getSettingData()->edgeThickness = ui->edgeLineEdit->text().toStdString();
    _facade->getSettingData()->edgeType = ui->typeComboBox->currentText().toStdString();
    _facade->getSettingData()->verticesColor = ui->verticesColorComboBox->currentText().toStdString();
    _facade->getSettingData()->verticesSize = ui->verticesLineEdit->text().toStdString();
    _facade->getSettingData()->verticesShape = ui->verticesShapeComboBox->currentText().toStdString();
    _facade->getSettingData()->projectionType = ui->projectionTypeComboBox->currentText().toStdString();
    _facade->getSettingData()->backgroundColor = ui->backgroundColorComboBox->currentText().toStdString();
    _facade->getSettingData()->calculateType = ui->calculateTypeComboBox->currentText().toStdString();
}

void SettingView::fillSettingDefault() {
    _facade->getSettingData()->edgeColor = "white";
    _facade->getSettingData()->edgeThickness = "1";
    _facade->getSettingData()->edgeType = "solid";
    _facade->getSettingData()->verticesColor = "white";
    _facade->getSettingData()->verticesSize = "1";
    _facade->getSettingData()->verticesShape = "none";
    _facade->getSettingData()->projectionType = "central";
    _facade->getSettingData()->backgroundColor = "black";
    _facade->getSettingData()->calculateType = "GPU";
}

void SettingView::on_edgeMinusButton_clicked() {
    if (_thickness > 1) {
        _thickness--;
        ui->edgeLineEdit->setText(QString::number(_thickness));
    }
}

void SettingView::on_edgePlusButton_clicked() {
    if (_thickness < 10) {
        _thickness++;
        ui->edgeLineEdit->setText(QString::number(_thickness));
    }
}

void SettingView::on_verticesMinusButton_clicked() {
    if (_size > 1) {
        _size--;
        ui->verticesLineEdit->setText(QString::number(_size));
    }
}
void SettingView::on_verticesPlusButton_clicked() {
    if (_size < 10) {
        _size++;
        ui->verticesLineEdit->setText(QString::number(_size));
    }
}

}  // namespace s21
