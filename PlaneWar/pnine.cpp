#include "pnine.h"
#include "ui_pnine.h"
#include"widget.h"

pnine::pnine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pnine)
{
    ui->setupUi(this);
    this->setWindowTitle("剧情");
    this-> setFixedSize(620,930);
}

pnine::~pnine()
{
    delete ui;
}

void pnine::on_pushButton_4_clicked()
{
    Widget *w=new Widget();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}
