#include "peight.h"
#include "ui_peight.h"
#include "widget.h"
#include "mainscene.h"


peight::peight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::peight)
{
    ui->setupUi(this);
    this->setWindowTitle("游戏规则");
    this-> setFixedSize(620,930);
}

peight::~peight()
{
    delete ui;
}

void peight::on_pushButton_3_clicked()
{
    //这里要转到mainscene
    MainScene *w=new MainScene();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void peight::on_pushButton_5_clicked()
{
    //写错了
}

void peight::on_pushButton_6_clicked()
{
    //到下一页
    MainScene *w=new MainScene();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void peight::on_pushButton_4_clicked()
{
    //回去
    Widget *w=new Widget();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
