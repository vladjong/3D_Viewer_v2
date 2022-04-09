#include "view/viewerView.h"

#include <QtWidgets/QApplication>

using namespace s21;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Figure figure;
    Facade facade(&figure);
    MainWindow w(&facade);
    w.show();
    return a.exec();
}
