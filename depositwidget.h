#ifndef DEPOSITWIDGET_H
#define DEPOSITWIDGET_H

#include <QWidget>
#include "bankingsystem.h"
using namespace std;
namespace Ui {
class depositWidget;
}

class depositWidget : public QWidget
{
    Q_OBJECT

public:
    explicit depositWidget(BankingSystem *bankingSystem, QWidget *parent = nullptr);
    ~depositWidget();
    void buttonDeposit();
    void buttonDepositCancel();

private:
    Ui::depositWidget *ui;
    BankingSystem *bankingSystem;
};

#endif // DEPOSITWIDGET_H
