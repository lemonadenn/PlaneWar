#include "pthree.h"
#include "ui_pthree.h"
#include "pfour.h"
#include "mainscene.h"
#include "widget.h"

pthree::pthree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pthree)
{
    ui->setupUi(this);\
    this->setWindowTitle("剧情");
    this-> setFixedSize(GAME_WIDTH,GAME_HEIGHT);
}

pthree::~pthree()
{
    delete ui;
}

void pthree::on_pushButton_3_clicked()
{
    pfour *w=new pfour();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pthree::on_pushButton_4_clicked()
{
    //到mainscene
    MainScene *w=new MainScene();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pthree::on_pushButton_5_clicked()
{
    //回初始
    Widget *w=new Widget();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
