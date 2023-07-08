#include "psix.h"
#include "ui_psix.h"
#include "pseven.h"
#include "mainscene.h"
#include "widget.h"

psix::psix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::psix)
{
    ui->setupUi(this);
    this->setWindowTitle("剧情");
    this-> setFixedSize(620,930);
}

psix::~psix()
{
    delete ui;
}

void psix::on_pushButton_3_clicked()
{
    pseven *w=new pseven();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void psix::on_pushButton_5_clicked()
{
    //回初始
    MainScene *w=new MainScene();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void psix::on_pushButton_4_clicked()
{
    //到mainscene
    Widget *w=new Widget();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
