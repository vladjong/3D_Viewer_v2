/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#pragma once

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "../view/glwidget.h"
#include "styles.h"

QT_BEGIN_NAMESPACE

namespace s21 {

class Ui_MainWindow {
 public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_9;
    QLabel *label_scale;
    QPushButton *btn_choose_file;
    QLineEdit *le_rotate_y;
    QLineEdit *le_translate_z;
    QLineEdit *le_model;
    QFrame *line_2;
    QLabel *label_translate_y;
    QSlider *slider_translate_y;
    QLabel *label_rotate_x;
    QLabel *label_model_2;
    QSlider *slider_rotate_z;
    QLineEdit *le_scale;
    QSlider *slider_rotate_x;
    QSlider *slider_rotate_y;
    QLineEdit *le_translate_y;
    QLabel *label_rotate_z;
    QLineEdit *le_rotate_x;
    QLabel *label_rotate_y;
    QSlider *slider_translate_z;
    QPushButton *btn_scale;
    QLineEdit *le_rotate_z;
    QLabel *label_rotate;
    QLabel *label_translate_x;
    QFrame *line_1;
    QLabel *label_translate;
    QPushButton *btn_translate;
    QLabel *label_translate_z;
    QLineEdit *le_translate_x;
    QPushButton *btn_rotate;
    QSlider *slider_scale;
    QFrame *line_3;
    QSlider *slider_translate_x;
    GLWidget *widget;
    QWidget *horizontalWidget_info;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_model_info;
    QLabel *label_model_set;
    QLabel *label_vertex_info;
    QLabel *label_vertex_set;
    QLabel *label_edge_info;
    QLabel *label_edge_set;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_settings;
    QPushButton *btn_screenshot;
    QPushButton *btn_screencast;

    void setupUi(QMainWindow *MainWindow) {
        if (MainWindow->objectName().isEmpty()) MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 950);
        MainWindow->setMinimumSize(QSize(1600, 950));
        MainWindow->setMaximumSize(QSize(1600, 950));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 143, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(0, 950));
        centralwidget->setStyleSheet(QString::fromUtf8("background: #1A1D21;"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1625, 931));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 50, 10);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_scale = new QLabel(horizontalLayoutWidget);
        label_scale->setObjectName(QString::fromUtf8("label_scale"));
        label_scale->setMinimumSize(QSize(0, 0));
        label_scale->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(18);
        label_scale->setFont(font);
        label_scale->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        label_scale->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_scale, 17, 0, 1, 3);

        btn_choose_file = new QPushButton(horizontalLayoutWidget);
        btn_choose_file->setObjectName(QString::fromUtf8("btn_choose_file"));
        btn_choose_file->setMinimumSize(QSize(0, 0));
        btn_choose_file->setMaximumSize(QSize(16777215, 40));
        btn_choose_file->setFont(font);
        btn_choose_file->setStyleSheet(QString::fromUtf8(BUTTON_STYLE));

        gridLayout_9->addWidget(btn_choose_file, 3, 0, 1, 3);

        le_rotate_y = new QLineEdit(horizontalLayoutWidget);
        le_rotate_y->setObjectName(QString::fromUtf8("le_rotate_y"));
        le_rotate_y->setMinimumSize(QSize(0, 0));
        le_rotate_y->setMaximumSize(QSize(16777215, 40));
        le_rotate_y->setFont(font);
        le_rotate_y->setStyleSheet(QString::fromUtf8(LINE_EDIT_STYLE));
        le_rotate_y->setMaxLength(5);

        gridLayout_9->addWidget(le_rotate_y, 13, 1, 1, 1);

        le_translate_z = new QLineEdit(horizontalLayoutWidget);
        le_translate_z->setObjectName(QString::fromUtf8("le_translate_z"));
        le_translate_z->setMinimumSize(QSize(0, 0));
        le_translate_z->setMaximumSize(QSize(16777215, 40));
        le_translate_z->setFont(font);
        le_translate_z->setStyleSheet(QString::fromUtf8(LINE_EDIT_STYLE));
        le_translate_z->setMaxLength(7);

        gridLayout_9->addWidget(le_translate_z, 8, 1, 1, 1);

        le_model = new QLineEdit(horizontalLayoutWidget);
        le_model->setObjectName(QString::fromUtf8("le_model"));
        le_model->setMinimumSize(QSize(0, 0));
        le_model->setMaximumSize(QSize(16777215, 40));
        le_model->setFont(font);
        le_model->setStyleSheet(QString::fromUtf8(LINE_EDIT_STYLE));
        le_model->setMaxLength(20);
        le_model->setReadOnly(true);

        gridLayout_9->addWidget(le_model, 2, 0, 1, 3);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(50, 0));
        line_2->setMaximumSize(QSize(1000, 5));
        line_2->setStyleSheet(QString::fromUtf8(LINE_STYLE));
        line_2->setFrameShadow(QFrame::Raised);
        line_2->setLineWidth(1);
        line_2->setFrameShape(QFrame::HLine);

        gridLayout_9->addWidget(line_2, 10, 0, 1, 3);

        label_translate_y = new QLabel(horizontalLayoutWidget);
        label_translate_y->setObjectName(QString::fromUtf8("label_translate_y"));
        label_translate_y->setMinimumSize(QSize(0, 0));
        label_translate_y->setMaximumSize(QSize(16777215, 40));
        label_translate_y->setFont(font);
        label_translate_y->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout_9->addWidget(label_translate_y, 7, 0, 1, 1);

        slider_translate_y = new QSlider(horizontalLayoutWidget);
        slider_translate_y->setObjectName(QString::fromUtf8("slider_translate_y"));
        slider_translate_y->setMinimumSize(QSize(0, 0));
        slider_translate_y->setMaximumSize(QSize(16777215, 40));
        slider_translate_y->setFont(font);
        slider_translate_y->setStyleSheet(QString::fromUtf8(""));
        slider_translate_y->setMinimum(-1000);
        slider_translate_y->setMaximum(1000);
        slider_translate_y->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(slider_translate_y, 7, 2, 1, 1);

        label_rotate_x = new QLabel(horizontalLayoutWidget);
        label_rotate_x->setObjectName(QString::fromUtf8("label_rotate_x"));
        label_rotate_x->setMinimumSize(QSize(0, 0));
        label_rotate_x->setMaximumSize(QSize(16777215, 40));
        label_rotate_x->setFont(font);
        label_rotate_x->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout_9->addWidget(label_rotate_x, 12, 0, 1, 1);

        label_model_2 = new QLabel(horizontalLayoutWidget);
        label_model_2->setObjectName(QString::fromUtf8("label_model_2"));
        label_model_2->setMinimumSize(QSize(0, 0));
        label_model_2->setMaximumSize(QSize(16777215, 20));
        label_model_2->setFont(font);
        label_model_2->setLayoutDirection(Qt::LeftToRight);
        label_model_2->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        label_model_2->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_model_2, 0, 0, 1, 3);

        slider_rotate_z = new QSlider(horizontalLayoutWidget);
        slider_rotate_z->setObjectName(QString::fromUtf8("slider_rotate_z"));
        slider_rotate_z->setMinimumSize(QSize(0, 0));
        slider_rotate_z->setMaximumSize(QSize(16777215, 40));
        slider_rotate_z->setFont(font);
        slider_rotate_z->setStyleSheet(QString::fromUtf8(""));
        slider_rotate_z->setMaximum(360);
        slider_rotate_z->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(slider_rotate_z, 14, 2, 1, 1);

        le_scale = new QLineEdit(horizontalLayoutWidget);
        le_scale->setObjectName(QString::fromUtf8("le_scale"));
        le_scale->setMinimumSize(QSize(0, 0));
        le_scale->setMaximumSize(QSize(16777215, 40));
        le_scale->setFont(font);
        le_scale->setStyleSheet(QString::fromUtf8(LINE_EDIT_STYLE));
        le_scale->setMaxLength(7);

        gridLayout_9->addWidget(le_scale, 19, 0, 1, 3);

        slider_rotate_x = new QSlider(horizontalLayoutWidget);
        slider_rotate_x->setObjectName(QString::fromUtf8("slider_rotate_x"));
        slider_rotate_x->setMinimumSize(QSize(0, 0));
        slider_rotate_x->setMaximumSize(QSize(16777215, 40));
        slider_rotate_x->setFont(font);
        slider_rotate_x->setStyleSheet(QString::fromUtf8(""));
        slider_rotate_x->setMaximum(360);
        slider_rotate_x->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(slider_rotate_x, 12, 2, 1, 1);

        slider_rotate_y = new QSlider(horizontalLayoutWidget);
        slider_rotate_y->setObjectName(QString::fromUtf8("slider_rotate_y"));
        slider_rotate_y->setMinimumSize(QSize(0, 0));
        slider_rotate_y->setMaximumSize(QSize(16777215, 40));
        slider_rotate_y->setFont(font);
        slider_rotate_y->setStyleSheet(QString::fromUtf8(""));
        slider_rotate_y->setMaximum(360);
        slider_rotate_y->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(slider_rotate_y, 13, 2, 1, 1);

        le_translate_y = new QLineEdit(horizontalLayoutWidget);
        le_translate_y->setObjectName(QString::fromUtf8("le_translate_y"));
        le_translate_y->setMinimumSize(QSize(0, 0));
        le_translate_y->setMaximumSize(QSize(16777215, 40));
        le_translate_y->setFont(font);
        le_translate_y->setStyleSheet(QString::fromUtf8(LINE_EDIT_STYLE));
        le_translate_y->setMaxLength(7);

        gridLayout_9->addWidget(le_translate_y, 7, 1, 1, 1);

        label_rotate_z = new QLabel(horizontalLayoutWidget);
        label_rotate_z->setObjectName(QString::fromUtf8("label_rotate_z"));
        label_rotate_z->setMinimumSize(QSize(0, 0));
        label_rotate_z->setMaximumSize(QSize(16777215, 40));
        label_rotate_z->setFont(font);
        label_rotate_z->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout_9->addWidget(label_rotate_z, 14, 0, 1, 1);

        le_rotate_x = new QLineEdit(horizontalLayoutWidget);
        le_rotate_x->setObjectName(QString::fromUtf8("le_rotate_x"));
        le_rotate_x->setMinimumSize(QSize(0, 0));
        le_rotate_x->setMaximumSize(QSize(16777215, 40));
        le_rotate_x->setFont(font);
        le_rotate_x->setStyleSheet(QString::fromUtf8(LINE_EDIT_STYLE));
        le_rotate_x->setMaxLength(5);

        gridLayout_9->addWidget(le_rotate_x, 12, 1, 1, 1);

        label_rotate_y = new QLabel(horizontalLayoutWidget);
        label_rotate_y->setObjectName(QString::fromUtf8("label_rotate_y"));
        label_rotate_y->setMinimumSize(QSize(0, 0));
        label_rotate_y->setMaximumSize(QSize(16777215, 40));
        label_rotate_y->setFont(font);
        label_rotate_y->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout_9->addWidget(label_rotate_y, 13, 0, 1, 1);

        slider_translate_z = new QSlider(horizontalLayoutWidget);
        slider_translate_z->setObjectName(QString::fromUtf8("slider_translate_z"));
        slider_translate_z->setMinimumSize(QSize(0, 0));
        slider_translate_z->setMaximumSize(QSize(16777215, 40));
        slider_translate_z->setFont(font);
        slider_translate_z->setStyleSheet(QString::fromUtf8(""));
        slider_translate_z->setMinimum(-1000);
        slider_translate_z->setMaximum(1000);
        slider_translate_z->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(slider_translate_z, 8, 2, 1, 1);

        btn_scale = new QPushButton(horizontalLayoutWidget);
        btn_scale->setObjectName(QString::fromUtf8("btn_scale"));
        btn_scale->setMinimumSize(QSize(0, 0));
        btn_scale->setMaximumSize(QSize(16777215, 40));
        btn_scale->setFont(font);
        btn_scale->setStyleSheet(QString::fromUtf8(BUTTON_STYLE));

        gridLayout_9->addWidget(btn_scale, 21, 0, 1, 3);

        le_rotate_z = new QLineEdit(horizontalLayoutWidget);
        le_rotate_z->setObjectName(QString::fromUtf8("le_rotate_z"));
        le_rotate_z->setMinimumSize(QSize(0, 0));
        le_rotate_z->setMaximumSize(QSize(16777215, 40));
        le_rotate_z->setFont(font);
        le_rotate_z->setStyleSheet(QString::fromUtf8(LINE_EDIT_STYLE));
        le_rotate_z->setMaxLength(5);

        gridLayout_9->addWidget(le_rotate_z, 14, 1, 1, 1);

        label_rotate = new QLabel(horizontalLayoutWidget);
        label_rotate->setObjectName(QString::fromUtf8("label_rotate"));
        label_rotate->setMinimumSize(QSize(0, 0));
        label_rotate->setMaximumSize(QSize(16777215, 20));
        label_rotate->setFont(font);
        label_rotate->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        label_rotate->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_rotate, 11, 0, 1, 3);

        label_translate_x = new QLabel(horizontalLayoutWidget);
        label_translate_x->setObjectName(QString::fromUtf8("label_translate_x"));
        label_translate_x->setMinimumSize(QSize(0, 0));
        label_translate_x->setMaximumSize(QSize(16777215, 40));
        label_translate_x->setFont(font);
        label_translate_x->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout_9->addWidget(label_translate_x, 6, 0, 1, 1);

        line_1 = new QFrame(horizontalLayoutWidget);
        line_1->setObjectName(QString::fromUtf8("line_1"));
        line_1->setMinimumSize(QSize(50, 0));
        line_1->setMaximumSize(QSize(1000, 5));
        line_1->setStyleSheet(QString::fromUtf8(LINE_STYLE));
        line_1->setFrameShadow(QFrame::Raised);
        line_1->setLineWidth(1);
        line_1->setFrameShape(QFrame::HLine);

        gridLayout_9->addWidget(line_1, 4, 0, 1, 3);

        label_translate = new QLabel(horizontalLayoutWidget);
        label_translate->setObjectName(QString::fromUtf8("label_translate"));
        label_translate->setMinimumSize(QSize(0, 0));
        label_translate->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        label_translate->setFont(font1);
        label_translate->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        label_translate->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_translate, 5, 0, 1, 3);

        btn_translate = new QPushButton(horizontalLayoutWidget);
        btn_translate->setObjectName(QString::fromUtf8("btn_translate"));
        btn_translate->setMinimumSize(QSize(0, 0));
        btn_translate->setMaximumSize(QSize(16777215, 40));
        btn_translate->setFont(font);
        btn_translate->setStyleSheet(QString::fromUtf8(BUTTON_STYLE));

        gridLayout_9->addWidget(btn_translate, 9, 0, 1, 3);

        label_translate_z = new QLabel(horizontalLayoutWidget);
        label_translate_z->setObjectName(QString::fromUtf8("label_translate_z"));
        label_translate_z->setMinimumSize(QSize(0, 0));
        label_translate_z->setMaximumSize(QSize(16777215, 40));
        label_translate_z->setFont(font);
        label_translate_z->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        gridLayout_9->addWidget(label_translate_z, 8, 0, 1, 1);

        le_translate_x = new QLineEdit(horizontalLayoutWidget);
        le_translate_x->setObjectName(QString::fromUtf8("le_translate_x"));
        le_translate_x->setMinimumSize(QSize(0, 0));
        le_translate_x->setMaximumSize(QSize(16777215, 40));
        le_translate_x->setFont(font);
        le_translate_x->setLayoutDirection(Qt::LeftToRight);
        le_translate_x->setStyleSheet(QString::fromUtf8(LINE_EDIT_STYLE));
        le_translate_x->setMaxLength(7);

        gridLayout_9->addWidget(le_translate_x, 6, 1, 1, 1);

        btn_rotate = new QPushButton(horizontalLayoutWidget);
        btn_rotate->setObjectName(QString::fromUtf8("btn_rotate"));
        btn_rotate->setMinimumSize(QSize(0, 0));
        btn_rotate->setMaximumSize(QSize(16777215, 40));
        btn_rotate->setFont(font);
        btn_rotate->setStyleSheet(QString::fromUtf8(BUTTON_STYLE));

        gridLayout_9->addWidget(btn_rotate, 15, 0, 1, 3);

        slider_scale = new QSlider(horizontalLayoutWidget);
        slider_scale->setObjectName(QString::fromUtf8("slider_scale"));
        slider_scale->setMinimumSize(QSize(0, 0));
        slider_scale->setMaximumSize(QSize(16777215, 40));
        slider_scale->setFont(font);
        slider_scale->setStyleSheet(QString::fromUtf8(""));
        slider_scale->setMaximum(400);
        slider_scale->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(slider_scale, 20, 0, 1, 3);

        line_3 = new QFrame(horizontalLayoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(50, 0));
        line_3->setMaximumSize(QSize(1000, 5));
        line_3->setStyleSheet(QString::fromUtf8(LINE_STYLE));
        line_3->setFrameShadow(QFrame::Raised);
        line_3->setLineWidth(1);
        line_3->setFrameShape(QFrame::HLine);

        gridLayout_9->addWidget(line_3, 16, 0, 1, 3);

        slider_translate_x = new QSlider(horizontalLayoutWidget);
        slider_translate_x->setObjectName(QString::fromUtf8("slider_translate_x"));
        slider_translate_x->setMinimumSize(QSize(150, 0));
        slider_translate_x->setMaximumSize(QSize(16777215, 40));
        slider_translate_x->setFont(font);
        slider_translate_x->setStyleSheet(QString::fromUtf8(""));
        slider_translate_x->setMinimum(-1000);
        slider_translate_x->setMaximum(1000);
        slider_translate_x->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(slider_translate_x, 6, 2, 1, 1);

        horizontalLayout->addLayout(gridLayout_9);

        widget = new GLWidget(horizontalLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(1200, 0));
        widget->setMaximumSize(QSize(1200, 16777215));
        widget->setCursor(QCursor(Qt::CrossCursor));
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalWidget_info = new QWidget(widget);
        horizontalWidget_info->setObjectName(QString::fromUtf8("horizontalWidget_info"));
        horizontalWidget_info->setGeometry(QRect(30, 860, 1201, 43));
        horizontalWidget_info->setStyleSheet(QString::fromUtf8("background-color: none;"));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_info);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_model_info = new QLabel(horizontalWidget_info);
        label_model_info->setObjectName(QString::fromUtf8("label_model_info"));
        label_model_info->setMinimumSize(QSize(80, 0));
        label_model_info->setMaximumSize(QSize(80, 16777215));
        QFont font2;
        font2.setPointSize(16);
        label_model_info->setFont(font2);
        label_model_info->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        label_model_info->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_model_info);

        label_model_set = new QLabel(horizontalWidget_info);
        label_model_set->setObjectName(QString::fromUtf8("label_model_set"));
        label_model_set->setFont(font2);
        label_model_set->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        horizontalLayout_2->addWidget(label_model_set);

        label_vertex_info = new QLabel(horizontalWidget_info);
        label_vertex_info->setObjectName(QString::fromUtf8("label_vertex_info"));
        label_vertex_info->setMinimumSize(QSize(80, 0));
        label_vertex_info->setMaximumSize(QSize(80, 16777215));
        label_vertex_info->setFont(font2);
        label_vertex_info->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        label_vertex_info->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_vertex_info);

        label_vertex_set = new QLabel(horizontalWidget_info);
        label_vertex_set->setObjectName(QString::fromUtf8("label_vertex_set"));
        label_vertex_set->setFont(font2);
        label_vertex_set->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        horizontalLayout_2->addWidget(label_vertex_set);

        label_edge_info = new QLabel(horizontalWidget_info);
        label_edge_info->setObjectName(QString::fromUtf8("label_edge_info"));
        label_edge_info->setMinimumSize(QSize(80, 0));
        label_edge_info->setMaximumSize(QSize(80, 16777215));
        label_edge_info->setFont(font2);
        label_edge_info->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));
        label_edge_info->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_edge_info);

        label_edge_set = new QLabel(horizontalWidget_info);
        label_edge_set->setObjectName(QString::fromUtf8("label_edge_set"));
        label_edge_set->setFont(font2);
        label_edge_set->setStyleSheet(QString::fromUtf8("color: #FCFEF1;"));

        horizontalLayout_2->addWidget(label_edge_set);

        verticalWidget = new QWidget(widget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setGeometry(QRect(1130, 10, 68, 194));
        verticalWidget->setStyleSheet(QString::fromUtf8("background-color: none;"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_settings = new QPushButton(verticalWidget);
        btn_settings->setObjectName(QString::fromUtf8("btn_settings"));
        btn_settings->setCursor(QCursor(Qt::ArrowCursor));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_settings->sizePolicy().hasHeightForWidth());
        btn_settings->setSizePolicy(sizePolicy1);
        btn_settings->setFocusPolicy(Qt::WheelFocus);
        btn_settings->setStyleSheet(QString::fromUtf8(BUTTON_EXTRA_STYLE));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_settings->setIcon(icon);
        btn_settings->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(btn_settings);

        btn_screenshot = new QPushButton(verticalWidget);
        btn_screenshot->setObjectName(QString::fromUtf8("btn_screenshot"));
        btn_screenshot->setCursor(QCursor(Qt::ArrowCursor));
        sizePolicy1.setHeightForWidth(btn_screenshot->sizePolicy().hasHeightForWidth());
        btn_screenshot->setSizePolicy(sizePolicy1);
        btn_screenshot->setFocusPolicy(Qt::WheelFocus);
        btn_screenshot->setStyleSheet(QString::fromUtf8(BUTTON_EXTRA_STYLE));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/screenshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_screenshot->setIcon(icon1);
        btn_screenshot->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(btn_screenshot);

        btn_screencast = new QPushButton(verticalWidget);
        btn_screencast->setObjectName(QString::fromUtf8("btn_screencast"));
        btn_screencast->setCursor(QCursor(Qt::ArrowCursor));
        sizePolicy1.setHeightForWidth(btn_screencast->sizePolicy().hasHeightForWidth());
        btn_screencast->setSizePolicy(sizePolicy1);
        btn_screencast->setFocusPolicy(Qt::WheelFocus);
        btn_screencast->setStyleSheet(QString::fromUtf8(BUTTON_EXTRA_STYLE));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/gif.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_screencast->setIcon(icon2);
        btn_screencast->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(btn_screencast);

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ViewerView", nullptr));
        label_scale->setText(QCoreApplication::translate("MainWindow", "SCALE", nullptr));
        btn_choose_file->setText(QCoreApplication::translate("MainWindow", "Choose file", nullptr));
        le_rotate_y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        le_translate_z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        le_model->setText(QString());
        label_translate_y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_rotate_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_model_2->setText(QCoreApplication::translate("MainWindow", "MODEL", nullptr));
        le_scale->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        le_translate_y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_rotate_z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        le_rotate_x->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_rotate_y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        btn_scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        le_rotate_z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_rotate->setText(QCoreApplication::translate("MainWindow", "ROTATE", nullptr));
        label_translate_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_translate->setText(QCoreApplication::translate("MainWindow", "TRANSLATE", nullptr));
        btn_translate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        label_translate_z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        le_translate_x->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_model_info->setText(QCoreApplication::translate("MainWindow", "MODEL:", nullptr));
        label_model_set->setText(QString());
        label_vertex_info->setText(QCoreApplication::translate("MainWindow", "VERTEX:", nullptr));
        label_vertex_set->setText(QString());
        label_edge_info->setText(QCoreApplication::translate("MainWindow", "EDGE:", nullptr));
        label_edge_set->setText(QString());
        btn_settings->setText(QString());
        btn_screenshot->setText(QString());
        btn_screencast->setText(QString());
    }  // retranslateUi
};

}  // namespace s21

namespace Ui {
class MainWindow : public s21::Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE
