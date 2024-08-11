#include "menuwidget.h"
#include "ui_menuwidget.h"

menuWidget::menuWidget(BankingSystem *bankingSystem, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menuWidget)
    , makeAccount(bankingSystem, this)
    , deposit(bankingSystem, this)
    , withdraw(bankingSystem, this)
{
    ui->setupUi(this);
    connect(ui->pushButton_make, &QPushButton::clicked, this, &menuWidget::buttonMakeAccount);
    connect(ui->pushButton_deposit, &QPushButton::clicked, this, &menuWidget::buttonDeposit);
    connect(ui->pushButton_withdraw, &QPushButton::clicked, this, &menuWidget::buttonWithDraw);
    //makeAccount.hide();
    //deposit.hide();
    //withdraw.hide();
}

menuWidget::~menuWidget()
{
    delete ui;
}
void menuWidget::buttonMakeAccount(){
    makeAccount.show();  //
    this->hide();

}
void menuWidget::buttonDeposit(){
    deposit.show();  //
    this->hide();

}
void menuWidget::buttonWithDraw(){
    withdraw.show();  //
    this->hide();

}
