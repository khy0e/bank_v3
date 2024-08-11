#include "withdrawwidget.h"
#include "ui_withdrawwidget.h"

#include <QMessageBox>

withdrawWidget::withdrawWidget(BankingSystem *bankingSystem, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::withdrawWidget),
    bankingSystem(bankingSystem)
{
    ui->setupUi(this);
    connect(ui->pushButton_wconfirm, &QPushButton::clicked, this, &withdrawWidget::buttonWithdraw);
    connect(ui->pushButton_wcancel, &QPushButton::clicked, this, &withdrawWidget::buttonWithdrawCancel);
}

withdrawWidget::~withdrawWidget()
{
    delete ui;
}

void withdrawWidget::buttonWithdraw()
{
    QString accountNumber = ui->lineEdit_wa->text();
    double amount = ui->spinBox_wm->value();

    try {
        if (bankingSystem->withdraw(accountNumber.toStdString(), amount)) {
            QMessageBox::information(this, "Withdraw Successful", "Amount withdrawn successfully.");
        } else {
            QMessageBox::warning(this, "Withdraw Failed", "Insufficient funds.");
        }
    } catch (const exception &e) {
        QMessageBox::warning(this, "Withdraw Failed", e.what());
    }
}

void withdrawWidget::buttonWithdrawCancel()
{
    //menuwidget.show();
    this->hide();
}
