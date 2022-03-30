#ifndef VIEWERVIEW_H
#define VIEWERVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ViewerView; }
QT_END_NAMESPACE

class ViewerView : public QMainWindow
{
    Q_OBJECT

public:
    ViewerView(QWidget *parent = nullptr);
    ~ViewerView();

private:
    Ui::ViewerView *ui;
};
#endif // VIEWERVIEW_H
