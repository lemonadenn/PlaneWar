#include "pone.h"
#include "ui_pone.h"
#include "ptwo.h"
#include "mainscene.h"
#include "widget.h"


pone::pone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pone)
{
    ui->setupUi(this);
    this->setWindowTitle("剧情");
    this-> setFixedSize(620,930);

}

pone::~pone()
{
    delete ui;
}

void pone::on_buttonone_clicked()
{
    ptwo *w=new ptwo();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pone::on_toolButton_clicked()
{
    ptwo *w=new ptwo();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}


void pone::on_label_linkActivated(const QString &link)
{

}

void pone::on_pushButton_3_clicked()
{
    //mainscene
    MainScene *w=new MainScene();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pone::on_pushButton_4_clicked()
{
    //初始
    Widget *w=new Widget();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
