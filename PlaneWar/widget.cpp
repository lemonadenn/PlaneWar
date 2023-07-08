#include "widget.h"
#include "ui_widget.h"
#include "pone.h"
#include "config.h"
#include "peight.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("开始游戏");
    this-> setFixedSize(GAME_WIDTH, GAME_HEIGHT);
}

Widget::~Widget()
{
    delete ui;
}
//跳转到下一界面
void Widget::on_Widget_destroyed()
{

}

void Widget::on_buttonzero_clicked()
{
    pone *w=new pone();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}



void Widget::on_pushButton_4_clicked()
{
    //peight
    peight *w=new peight();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
