#include "makeaccountwidget.h"
#include "ui_makeaccountwidget.h"
#include <QMessageBox>
makeAccountWidget::makeAccountWidget(BankingSystem *bankingSystem, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::makeAccountWidget), bankingSystem(bankingSystem)
{
    ui->setupUi(this);
    connect(ui->pushButton_mconfirm, &QPushButton::clicked, this, &makeAccountWidget::buttonNewAccount);
    connect(ui->pushButton_mcancel, &QPushButton::clicked, this, &makeAccountWidget::buttonNewAccountCancel);

}

makeAccountWidget::~makeAccountWidget()
{
    delete ui;
}
void makeAccountWidget::buttonNewAccount()
{
    QString name = ui->lineEdit_mn->text();
    QString accountNumber = ui->lineEdit_ma->text();
    double initialBalance = ui->spinBox_mb->value();

    try {
        bankingSystem->createAccount(name.toStdString(), accountNumber.toStdString(), initialBalance);
        QMessageBox::information(this, "Account Created", "Account created successfully.");

    } catch (const exception &e) {
        QMessageBox::warning(this, "Creation Failed", e.what());
    }
}

void makeAccountWidget::buttonNewAccountCancel()
{
    //menuwidget.show();
    this->hide();
}
