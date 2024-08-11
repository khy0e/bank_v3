#ifndef WITHDRAWWIDGET_H
#define WITHDRAWWIDGET_H

#include <QWidget>
#include "bankingsystem.h"
using namespace std;

namespace Ui {
class withdrawWidget;
}

class withdrawWidget : public QWidget
{
    Q_OBJECT

public:
    explicit withdrawWidget(BankingSystem *bankingSystem, QWidget *parent = nullptr);
    ~withdrawWidget();
    void buttonWithdraw();
    void buttonWithdrawCancel();

private:
    Ui::withdrawWidget *ui;
    BankingSystem *bankingSystem;
};

#endif // WITHDRAWWIDGET_H
