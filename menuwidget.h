#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include "makeaccountwidget.h"
#include "depositwidget.h"
#include "withdrawwidget.h"
#include "bankingsystem.h"
using namespace std;
namespace Ui {
class menuWidget;
}

class menuWidget : public QWidget
{
    Q_OBJECT

public:

    explicit menuWidget(BankingSystem *bankingSystem, QWidget *parent = nullptr);
    ~menuWidget();
    void buttonMakeAccount();
    void buttonDeposit();
    void buttonWithDraw();

private:
    Ui::menuWidget *ui;
    makeAccountWidget makeAccount;
    depositWidget deposit;
    withdrawWidget withdraw;
};

#endif // MENUWIDGET_H
