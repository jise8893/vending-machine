#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <sstream>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
     ui->setupUi(this);
     ui->pbMilk->setEnabled(false);
     ui->pbCoffee->setEnabled(false);
     ui->pbTea->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);
}
void Widget::checkMoney()
{
    if(money>=150)
        ui->pbTea->setEnabled(true);
    else
        ui->pbTea->setEnabled(false);
    if(money>=100)
        ui->pbCoffee->setEnabled(true);
    else
        ui->pbCoffee->setEnabled(false);
    if(money>=200)
        ui->pbMilk->setEnabled(true);
    else
        ui->pbMilk->setEnabled(false);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    checkMoney();
}
void Widget::on_pb50_clicked()
{
     changeMoney(50);
     checkMoney();
}

void Widget::on_pb100_clicked()
{
     changeMoney(100);
     checkMoney();

}

void Widget::on_pb500_clicked()
{
     changeMoney(500);
     checkMoney();
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    checkMoney();
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
    checkMoney();
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    checkMoney();
}

void Widget::on_pbReset_clicked()
{
       QMessageBox m;
       //char array[20];
       //sprintf(array,"money : %d",money);
       QString str =QString::number(money);
       m.information(this,"money",str);
}
