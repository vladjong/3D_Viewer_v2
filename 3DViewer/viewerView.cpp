#include "viewerView.h"
#include "ui_viewerView.h"

ViewerView::ViewerView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewerView)
{
    ui->setupUi(this);
}

ViewerView::~ViewerView()
{
    delete ui;
}

