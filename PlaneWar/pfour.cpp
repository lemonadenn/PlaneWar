#include "pfour.h"
#include "ui_pfour.h"
#include "pfive.h"
#include "mainscene.h"
#include "widget.h"

pfour::pfour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pfour)
{
    ui->setupUi(this);
    this->setWindowTitle("剧情");
    this-> setFixedSize(620,930);
}

pfour::~pfour()
{
    delete ui;
}

void pfour::on_pushButton_3_clicked()
{
    pfive *w=new pfive();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pfour::on_pushButton_4_clicked()
{
    //到mainscene
    MainScene *w=new MainScene();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pfour::on_pushButton_5_clicked()
{
    //回初始
    Widget *w=new Widget();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
