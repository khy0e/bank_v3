#include "widget.h"
#include <QMessageBox>
#include <QPushButton>
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , bankingSystem(make_shared<BankingSystem>())
{
    ui->setupUi(this);
    connect(ui->pushButton_login, &QPushButton::clicked, this, &Widget::login);
    menuwidget.hide();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::login(){
    QString nameText = ui->nameEdit->text();  // textEdit에서 입력받은 텍스트 가져오기

    if (nameText == "test") {
        this->hide();
        menuwidget.show();  // 입력된 텍스트가 "test"인 경우 새 창 열기
        //this->hide();
    } else if (nameText == "hint") {
        QMessageBox::information(this, "Hint", "ID is \"test\"");  // "Hint"라는 제목과 함께 메시지 창 띄우기
    } else {
        QMessageBox::warning(this, "Login Failed", "Login failed!");  // 경고 창을 띄우기
    }
}

