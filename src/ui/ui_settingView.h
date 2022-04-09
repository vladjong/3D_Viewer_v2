/********************************************************************************
** Form generated from reading UI file 'settingView.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include "styles.h"

QT_BEGIN_NAMESPACE

namespace s21 {

class Ui_SettingView {
 public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *typeComboBox;
    QFrame *line_9;
    QComboBox *verticesColorComboBox;
    QPushButton *edgeMinusButton;
    QFrame *line_10;
    QLabel *projectionTypeLabel;
    QLabel *edgesLabel;
    QLabel *verticesShapeLabel;
    QLabel *verticesLabel;
    QPushButton *verticesPlusButton;
    QLabel *backgroundColorLabel;
    QLabel *typeLabel;
    QPushButton *verticesMinusButton;
    QComboBox *calculateTypeComboBox;
    QLabel *verticesSizeLabel;
    QComboBox *verticesShapeComboBox;
    QLabel *verticesColorLabel;
    QComboBox *projectionTypeComboBox;
    QLineEdit *edgeLineEdit;
    QLabel *otherLabel;
    QComboBox *edgeColorComboBox;
    QPushButton *edgePlusButton;
    QLabel *ThicknessLabel;
    QLabel *calculateTypeLabel;
    QLineEdit *verticesLineEdit;
    QLabel *edgeColorLabel;
    QComboBox *backgroundColorComboBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *resetButton;
    QPushButton *cancelButton;
    QPushButton *applyButton;

    void setupUi(QDialog *SettingView) {
        if (SettingView->objectName().isEmpty())
            SettingView->setObjectName(QString::fromUtf8("SettingView"));
        SettingView->resize(500, 700);
        SettingView->setMinimumSize(QSize(500, 700));
        SettingView->setMaximumSize(QSize(500, 700));
        SettingView->setStyleSheet(QString::fromUtf8("background: #292A2D;"));
        gridLayoutWidget = new QWidget(SettingView);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 481, 611));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        typeComboBox = new QComboBox(gridLayoutWidget);
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        font.setPointSize(14);
        typeComboBox->setFont(font);
        typeComboBox->setStyleSheet(QString::fromUtf8(COMBO_BOX_STYLE));

        gridLayout->addWidget(typeComboBox, 3, 1, 1, 1);

        line_9 = new QFrame(gridLayoutWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setMinimumSize(QSize(50, 0));
        line_9->setMaximumSize(QSize(1000, 5));
        line_9->setStyleSheet(QString::fromUtf8(LINE_STYLE));
        line_9->setFrameShadow(QFrame::Raised);
        line_9->setLineWidth(1);
        line_9->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_9, 4, 0, 1, 4);

        verticesColorComboBox = new QComboBox(gridLayoutWidget);
        verticesColorComboBox->addItem(QString());
        verticesColorComboBox->addItem(QString());
        verticesColorComboBox->addItem(QString());
        verticesColorComboBox->addItem(QString());
        verticesColorComboBox->addItem(QString());
        verticesColorComboBox->setObjectName(QString::fromUtf8("verticesColorComboBox"));
        verticesColorComboBox->setFont(font);
        verticesColorComboBox->setStyleSheet(QString::fromUtf8(COMBO_BOX_STYLE));

        gridLayout->addWidget(verticesColorComboBox, 6, 1, 1, 1);

        edgeMinusButton = new QPushButton(gridLayoutWidget);
        edgeMinusButton->setObjectName(QString::fromUtf8("edgeMinusButton"));
        edgeMinusButton->setMinimumSize(QSize(50, 0));
        edgeMinusButton->setMaximumSize(QSize(40, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans")});
        font1.setPointSize(18);
        font1.setBold(true);
        edgeMinusButton->setFont(font1);
        edgeMinusButton->setStyleSheet(QString::fromUtf8(BUTTON_SPIN_STYLE));
        edgeMinusButton->setIconSize(QSize(30, 30));
        edgeMinusButton->setFlat(false);

        gridLayout->addWidget(edgeMinusButton, 2, 2, 1, 1);

        line_10 = new QFrame(gridLayoutWidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setMinimumSize(QSize(50, 0));
        line_10->setMaximumSize(QSize(1000, 5));
        line_10->setStyleSheet(QString::fromUtf8(LINE_STYLE));
        line_10->setFrameShadow(QFrame::Raised);
        line_10->setLineWidth(1);
        line_10->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_10, 9, 0, 1, 4);

        projectionTypeLabel = new QLabel(gridLayoutWidget);
        projectionTypeLabel->setObjectName(QString::fromUtf8("projectionTypeLabel"));
        projectionTypeLabel->setFont(font);
        projectionTypeLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout->addWidget(projectionTypeLabel, 11, 0, 1, 1);

        edgesLabel = new QLabel(gridLayoutWidget);
        edgesLabel->setObjectName(QString::fromUtf8("edgesLabel"));
        edgesLabel->setMinimumSize(QSize(0, 20));
        edgesLabel->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Open Sans")});
        font2.setPointSize(18);
        edgesLabel->setFont(font2);
        edgesLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        edgesLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(edgesLabel, 0, 0, 1, 4);

        verticesShapeLabel = new QLabel(gridLayoutWidget);
        verticesShapeLabel->setObjectName(QString::fromUtf8("verticesShapeLabel"));
        verticesShapeLabel->setFont(font);
        verticesShapeLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout->addWidget(verticesShapeLabel, 8, 0, 1, 1);

        verticesLabel = new QLabel(gridLayoutWidget);
        verticesLabel->setObjectName(QString::fromUtf8("verticesLabel"));
        verticesLabel->setMinimumSize(QSize(0, 20));
        verticesLabel->setMaximumSize(QSize(16777215, 20));
        verticesLabel->setFont(font2);
        verticesLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        verticesLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(verticesLabel, 5, 0, 1, 4);

        verticesPlusButton = new QPushButton(gridLayoutWidget);
        verticesPlusButton->setObjectName(QString::fromUtf8("verticesPlusButton"));
        verticesPlusButton->setFont(font1);
        verticesPlusButton->setStyleSheet(QString::fromUtf8(BUTTON_SPIN_STYLE));

        gridLayout->addWidget(verticesPlusButton, 7, 3, 1, 1);

        backgroundColorLabel = new QLabel(gridLayoutWidget);
        backgroundColorLabel->setObjectName(QString::fromUtf8("backgroundColorLabel"));
        backgroundColorLabel->setFont(font);
        backgroundColorLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout->addWidget(backgroundColorLabel, 12, 0, 1, 1);

        typeLabel = new QLabel(gridLayoutWidget);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setFont(font);
        typeLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout->addWidget(typeLabel, 3, 0, 1, 1);

        verticesMinusButton = new QPushButton(gridLayoutWidget);
        verticesMinusButton->setObjectName(QString::fromUtf8("verticesMinusButton"));
        verticesMinusButton->setMinimumSize(QSize(50, 0));
        verticesMinusButton->setMaximumSize(QSize(40, 16777215));
        verticesMinusButton->setFont(font1);
        verticesMinusButton->setStyleSheet(QString::fromUtf8(BUTTON_SPIN_STYLE));

        gridLayout->addWidget(verticesMinusButton, 7, 2, 1, 1);

        calculateTypeComboBox = new QComboBox(gridLayoutWidget);
        calculateTypeComboBox->addItem(QString());
        calculateTypeComboBox->addItem(QString());
        calculateTypeComboBox->setObjectName(QString::fromUtf8("calculateTypeComboBox"));
        calculateTypeComboBox->setFont(font);
        calculateTypeComboBox->setStyleSheet(QString::fromUtf8(COMBO_BOX_STYLE));

        gridLayout->addWidget(calculateTypeComboBox, 13, 1, 1, 1);

        verticesSizeLabel = new QLabel(gridLayoutWidget);
        verticesSizeLabel->setObjectName(QString::fromUtf8("verticesSizeLabel"));
        verticesSizeLabel->setFont(font);
        verticesSizeLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout->addWidget(verticesSizeLabel, 7, 0, 1, 1);

        verticesShapeComboBox = new QComboBox(gridLayoutWidget);
        verticesShapeComboBox->addItem(QString());
        verticesShapeComboBox->addItem(QString());
        verticesShapeComboBox->addItem(QString());
        verticesShapeComboBox->setObjectName(QString::fromUtf8("verticesShapeComboBox"));
        verticesShapeComboBox->setFont(font);
        verticesShapeComboBox->setStyleSheet(QString::fromUtf8(COMBO_BOX_STYLE));

        gridLayout->addWidget(verticesShapeComboBox, 8, 1, 1, 1);

        verticesColorLabel = new QLabel(gridLayoutWidget);
        verticesColorLabel->setObjectName(QString::fromUtf8("verticesColorLabel"));
        verticesColorLabel->setFont(font);
        verticesColorLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout->addWidget(verticesColorLabel, 6, 0, 1, 1);

        projectionTypeComboBox = new QComboBox(gridLayoutWidget);
        projectionTypeComboBox->addItem(QString());
        projectionTypeComboBox->addItem(QString());
        projectionTypeComboBox->setObjectName(QString::fromUtf8("projectionTypeComboBox"));
        projectionTypeComboBox->setFont(font);
        projectionTypeComboBox->setStyleSheet(QString::fromUtf8(COMBO_BOX_STYLE));

        gridLayout->addWidget(projectionTypeComboBox, 11, 1, 1, 1);

        edgeLineEdit = new QLineEdit(gridLayoutWidget);
        edgeLineEdit->setObjectName(QString::fromUtf8("edgeLineEdit"));
        edgeLineEdit->setFont(font);
        edgeLineEdit->setStyleSheet(QString::fromUtf8(LINE_EDIT_SETTING_STYLE));
        edgeLineEdit->setMaxLength(3);
        edgeLineEdit->setDragEnabled(false);
        edgeLineEdit->setReadOnly(true);

        gridLayout->addWidget(edgeLineEdit, 2, 1, 1, 1);

        otherLabel = new QLabel(gridLayoutWidget);
        otherLabel->setObjectName(QString::fromUtf8("otherLabel"));
        otherLabel->setMinimumSize(QSize(0, 20));
        otherLabel->setMaximumSize(QSize(16777215, 20));
        otherLabel->setFont(font2);
        otherLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        otherLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(otherLabel, 10, 0, 1, 4);

        edgeColorComboBox = new QComboBox(gridLayoutWidget);
        edgeColorComboBox->addItem(QString());
        edgeColorComboBox->addItem(QString());
        edgeColorComboBox->addItem(QString());
        edgeColorComboBox->addItem(QString());
        edgeColorComboBox->addItem(QString());
        edgeColorComboBox->setObjectName(QString::fromUtf8("edgeColorComboBox"));
        edgeColorComboBox->setMinimumSize(QSize(0, 0));
        edgeColorComboBox->setFont(font);
        edgeColorComboBox->setStyleSheet(QString::fromUtf8(COMBO_BOX_STYLE));

        gridLayout->addWidget(edgeColorComboBox, 1, 1, 1, 1);

        edgePlusButton = new QPushButton(gridLayoutWidget);
        edgePlusButton->setObjectName(QString::fromUtf8("edgePlusButton"));
        edgePlusButton->setMinimumSize(QSize(50, 0));
        edgePlusButton->setFont(font1);
        edgePlusButton->setStyleSheet(QString::fromUtf8(BUTTON_SPIN_STYLE));

        gridLayout->addWidget(edgePlusButton, 2, 3, 1, 1);

        ThicknessLabel = new QLabel(gridLayoutWidget);
        ThicknessLabel->setObjectName(QString::fromUtf8("ThicknessLabel"));
        ThicknessLabel->setFont(font);
        ThicknessLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout->addWidget(ThicknessLabel, 2, 0, 1, 1);

        calculateTypeLabel = new QLabel(gridLayoutWidget);
        calculateTypeLabel->setObjectName(QString::fromUtf8("calculateTypeLabel"));
        calculateTypeLabel->setFont(font);
        calculateTypeLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout->addWidget(calculateTypeLabel, 13, 0, 1, 1);

        verticesLineEdit = new QLineEdit(gridLayoutWidget);
        verticesLineEdit->setObjectName(QString::fromUtf8("verticesLineEdit"));
        verticesLineEdit->setFont(font);
        verticesLineEdit->setStyleSheet(QString::fromUtf8(LINE_EDIT_SETTING_STYLE));
        verticesLineEdit->setMaxLength(3);
        verticesLineEdit->setReadOnly(true);

        gridLayout->addWidget(verticesLineEdit, 7, 1, 1, 1);

        edgeColorLabel = new QLabel(gridLayoutWidget);
        edgeColorLabel->setObjectName(QString::fromUtf8("edgeColorLabel"));
        edgeColorLabel->setFont(font);
        edgeColorLabel->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout->addWidget(edgeColorLabel, 1, 0, 1, 1);

        backgroundColorComboBox = new QComboBox(gridLayoutWidget);
        backgroundColorComboBox->addItem(QString());
        backgroundColorComboBox->addItem(QString());
        backgroundColorComboBox->addItem(QString());
        backgroundColorComboBox->setObjectName(QString::fromUtf8("backgroundColorComboBox"));
        backgroundColorComboBox->setFont(font);
        backgroundColorComboBox->setStyleSheet(QString::fromUtf8(COMBO_BOX_STYLE));

        gridLayout->addWidget(backgroundColorComboBox, 12, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(SettingView);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 630, 481, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        resetButton = new QPushButton(horizontalLayoutWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setMinimumSize(QSize(250, 35));
        resetButton->setMaximumSize(QSize(250, 16777215));
        resetButton->setFont(font);
        resetButton->setStyleSheet(QString::fromUtf8(BUTTON_STYLE));

        horizontalLayout->addWidget(resetButton);

        cancelButton = new QPushButton(horizontalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(0, 35));
        cancelButton->setFont(font);
        cancelButton->setStyleSheet(QString::fromUtf8(BUTTON_STYLE));

        horizontalLayout->addWidget(cancelButton);

        applyButton = new QPushButton(horizontalLayoutWidget);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setMinimumSize(QSize(0, 35));
        applyButton->setFont(font);
        applyButton->setStyleSheet(QString::fromUtf8(BUTTON_STYLE));

        horizontalLayout->addWidget(applyButton);

        retranslateUi(SettingView);

        edgeMinusButton->setDefault(false);

        QMetaObject::connectSlotsByName(SettingView);
    }  // setupUi

    void retranslateUi(QDialog *SettingView) {
        SettingView->setWindowTitle(QCoreApplication::translate("SettingView", "Dialog", nullptr));
        typeComboBox->setItemText(0, QCoreApplication::translate("SettingView", "solid", nullptr));
        typeComboBox->setItemText(1, QCoreApplication::translate("SettingView", "dotted", nullptr));

        verticesColorComboBox->setItemText(0, QCoreApplication::translate("SettingView", "white", nullptr));
        verticesColorComboBox->setItemText(1, QCoreApplication::translate("SettingView", "blue", nullptr));
        verticesColorComboBox->setItemText(2, QCoreApplication::translate("SettingView", "green", nullptr));
        verticesColorComboBox->setItemText(3, QCoreApplication::translate("SettingView", "yellow", nullptr));
        verticesColorComboBox->setItemText(4, QCoreApplication::translate("SettingView", "red", nullptr));

        edgeMinusButton->setText(QCoreApplication::translate("SettingView", "-", nullptr));
        projectionTypeLabel->setText(QCoreApplication::translate("SettingView", "Projection type", nullptr));
        edgesLabel->setText(QCoreApplication::translate("SettingView", "EDGES", nullptr));
        verticesShapeLabel->setText(QCoreApplication::translate("SettingView", "Shape", nullptr));
        verticesLabel->setText(QCoreApplication::translate("SettingView", "VERTICES", nullptr));
        verticesPlusButton->setText(QCoreApplication::translate("SettingView", "+", nullptr));
        backgroundColorLabel->setText(
            QCoreApplication::translate("SettingView", "Background color", nullptr));
        typeLabel->setText(QCoreApplication::translate("SettingView", "Type", nullptr));
        verticesMinusButton->setText(QCoreApplication::translate("SettingView", "-", nullptr));
        calculateTypeComboBox->setItemText(0, QCoreApplication::translate("SettingView", "GPU", nullptr));
        calculateTypeComboBox->setItemText(1, QCoreApplication::translate("SettingView", "CPU", nullptr));

        verticesSizeLabel->setText(QCoreApplication::translate("SettingView", "Size", nullptr));
        verticesShapeComboBox->setItemText(0, QCoreApplication::translate("SettingView", "none", nullptr));
        verticesShapeComboBox->setItemText(1, QCoreApplication::translate("SettingView", "circle", nullptr));
        verticesShapeComboBox->setItemText(2, QCoreApplication::translate("SettingView", "square", nullptr));

        verticesColorLabel->setText(QCoreApplication::translate("SettingView", "Vertices color", nullptr));
        projectionTypeComboBox->setItemText(0,
                                            QCoreApplication::translate("SettingView", "central", nullptr));
        projectionTypeComboBox->setItemText(1,
                                            QCoreApplication::translate("SettingView", "parallel", nullptr));

        edgeLineEdit->setText(QCoreApplication::translate("SettingView", "1", nullptr));
        otherLabel->setText(QCoreApplication::translate("SettingView", "OTHER", nullptr));
        edgeColorComboBox->setItemText(0, QCoreApplication::translate("SettingView", "white", nullptr));
        edgeColorComboBox->setItemText(1, QCoreApplication::translate("SettingView", "blue", nullptr));
        edgeColorComboBox->setItemText(2, QCoreApplication::translate("SettingView", "green", nullptr));
        edgeColorComboBox->setItemText(3, QCoreApplication::translate("SettingView", "yellow", nullptr));
        edgeColorComboBox->setItemText(4, QCoreApplication::translate("SettingView", "red", nullptr));

        edgePlusButton->setText(QCoreApplication::translate("SettingView", "+", nullptr));
        ThicknessLabel->setText(QCoreApplication::translate("SettingView", "Thickness", nullptr));
        calculateTypeLabel->setText(QCoreApplication::translate("SettingView", "Calculate type", nullptr));
        verticesLineEdit->setText(QCoreApplication::translate("SettingView", "1", nullptr));
        edgeColorLabel->setText(QCoreApplication::translate("SettingView", "Edge color", nullptr));
        backgroundColorComboBox->setItemText(0,
                                             QCoreApplication::translate("SettingView", "black", nullptr));
        backgroundColorComboBox->setItemText(1,
                                             QCoreApplication::translate("SettingView", "dracula", nullptr));
        backgroundColorComboBox->setItemText(2,
                                             QCoreApplication::translate("SettingView", "brown", nullptr));

        resetButton->setText(QCoreApplication::translate("SettingView", "RESET TO DEFAULT", nullptr));
        cancelButton->setText(QCoreApplication::translate("SettingView", "CANCEL", nullptr));
        applyButton->setText(QCoreApplication::translate("SettingView", "APPLY", nullptr));
    }  // retranslateUi
};

}  // namespace s21

namespace Ui {
class SettingView : public s21::Ui_SettingView {};
}  // namespace Ui

QT_END_NAMESPACE
