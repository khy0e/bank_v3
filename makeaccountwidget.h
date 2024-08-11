#ifndef MAKEACCOUNTWIDGET_H
#define MAKEACCOUNTWIDGET_H

#include <QWidget>
#include "bankingsystem.h"
using namespace std;
namespace Ui {
class makeAccountWidget;
}

class makeAccountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit makeAccountWidget(BankingSystem *bankingSystem, QWidget *parent = nullptr);
    ~makeAccountWidget();
    void buttonNewAccount();
    void buttonNewAccountCancel();

private:
    Ui::makeAccountWidget *ui;
    BankingSystem *bankingSystem;
};

#endif // MAKEACCOUNTWIDGET_H
