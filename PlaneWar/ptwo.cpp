#include "ptwo.h"
#include "ui_ptwo.h"
#include "pthree.h"
#include<QLabel>
#include "mainscene.h"
#include "widget.h"

ptwo::ptwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ptwo)
{
    ui->setupUi(this);
    this->setWindowTitle("前情提要");
    this-> setFixedSize(GAME_WIDTH,GAME_HEIGHT);

}

ptwo::~ptwo()
{
    delete ui;
}

void ptwo::on_buttontwo_clicked()
{
    pthree *w=new pthree();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}



void ptwo::on_pushButton_4_clicked()
{
    //到mainscene
    MainScene *w=new MainScene();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void ptwo::on_pushButton_5_clicked()
{
    //回初始
    Widget *w=new Widget();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void ptwo::on_pushButton_3_clicked()
{
    pthree *w=new pthree();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
