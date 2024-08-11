#include "depositwidget.h"
#include "ui_depositwidget.h"
#include <QMessageBox>

depositWidget::depositWidget(BankingSystem *bankingSystem, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::depositWidget), bankingSystem(bankingSystem)
{
    ui->setupUi(this);
    connect(ui->pushButton_dconfirm, &QPushButton::clicked, this, &depositWidget::buttonDeposit);
    connect(ui->pushButton_dcancel, &QPushButton::clicked, this, &depositWidget::buttonDepositCancel);
}

depositWidget::~depositWidget()
{
    delete ui;
}
void depositWidget::buttonDeposit()
{
    QString accountNumber = ui->lineEdit_da->text();
    double amount = ui->amountSpinBox->value();

    try {
        bankingSystem->deposit(accountNumber.toStdString(), amount);
        QMessageBox::information(this, "Deposit Successful", "Amount deposited successfully.");
    } catch (const exception &e) {
        QMessageBox::warning(this, "Deposit Failed", e.what());
    }
}

void depositWidget::buttonDepositCancel()
{
    //menuwidget.show();
    this->hide();
}
