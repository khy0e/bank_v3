#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include "menuwidget.h"
#include "bankingsystem.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent=nullptr);
    ~Widget();
    void login();

private:
    Ui::Widget *ui;
    menuWidget  menuwidget;
    shared_ptr<BankingSystem> bankingSystem;

};
#endif // WIDGET_H
