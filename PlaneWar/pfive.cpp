#include "pfive.h"
#include "ui_pfive.h"
#include "psix.h"
#include "mainscene.h"
#include "widget.h"

pfive::pfive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pfive)
{
    ui->setupUi(this);
    this->setWindowTitle("剧情");
    this-> setFixedSize(620,930);
}

pfive::~pfive()
{
    delete ui;
}

void pfive::on_pushButton_3_clicked()
{
    psix *w=new psix();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pfive::on_pushButton_4_clicked()
{
    //到mainscene
    MainScene *w=new MainScene();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pfive::on_pushButton_5_clicked()
{
    //回初始
    Widget *w=new Widget();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
