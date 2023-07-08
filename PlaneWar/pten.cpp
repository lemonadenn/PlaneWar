#include "pten.h"
#include "ui_pten.h"
#include "config.h"

pten::pten(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pten)
{
    ui->setupUi(this);
    this->setWindowTitle("剧情");
    this-> setFixedSize(620,930);
}

pten::~pten()
{
    delete ui;
}
