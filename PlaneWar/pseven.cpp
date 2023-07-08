#include "pseven.h"
#include "ui_pseven.h"
#include "mainscene.h"
#include "widget.h"
#include "peight.h"


#include <QLabel>
#include <QPixmap>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QGridLayout>
#include <QPropertyAnimation>


pseven::pseven(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pseven)
{
    ui->setupUi(this);
    this->setWindowTitle("剧情");
    this-> setFixedSize(620,930);
}

pseven::~pseven()
{
    delete ui;
}

void pseven::on_pushButton_4_clicked()
{
    //到mainscene
    MainScene *w=new MainScene();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pseven::on_pushButton_5_clicked()
{
    //到widget
    Widget *w=new Widget();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

void pseven::on_pushButton_3_clicked()
{
    peight *w=new peight();
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    this->hide();
}

/*void pseven::InitWidget()
{
    //Label
    m_pLbTest1 = new QLabel;
    m_pLbTest1->setScaledContents( true );
    QPixmap pix1( ":/ui/9.png" );
    m_pLbTest1->setPixmap( pix1 );

    //List Widget
    m_pListWidget = new QListWidget;
    m_pListWidget->setStyleSheet("QListWidget::Item{ padding-top:3px; padding-bottom:3px; height:60px;}");

    QListWidgetItem* pItem1 = new QListWidgetItem( m_pListWidget );
    m_pListWidget->addItem( pItem1 );
    m_pListWidget->setItemWidget( pItem1, m_pLbTest1 );
    //Buttons

    ui->pBtnEnter->setFixedSize(620,930);
    QHBoxLayout* pBtnLayout = new QHBoxLayout;
    pBtnLayout->addWidget( ui->pBtnEnter );

    //Main Layout
    QWidget* pCentralWidget = new QWidget;
    QVBoxLayout* pMainLayout = new QVBoxLayout;
    pMainLayout->addWidget( m_pListWidget );
    pMainLayout->addLayout( pBtnLayout );
    pCentralWidget->setLayout( pMainLayout );
    //Connects
    connect( ui->pBtnEnter, SIGNAL( clicked() ), this, SLOT( slotBtnEnter() ) );
}

void pseven::slotBtnEnter()
{
    QLabel* pCurWiget = new QLabel;
    pCurWiget->setScaledContents( true );
    QPixmap pix1( ":/ui/9.png" );
    pCurWiget->setPixmap( pix1 );

    QListWidgetItem* pItem = new QListWidgetItem( m_pListWidget );
    m_pListWidget->addItem( pItem );
    m_pListWidget->setItemWidget( pItem, pCurWiget );
    m_pListWidget->setCurrentItem( pItem );

    QPropertyAnimation* pAnimation = new QPropertyAnimation( pCurWiget, "pos" );
    pAnimation->setDuration( 3000 );
    pAnimation->setStartValue( QPointF( -pCurWiget->width(), pCurWiget->pos().y() ) );
    pAnimation->setEndValue( QPointF( 0, pCurWiget->pos().y() ) );
    pAnimation->setEasingCurve( QEasingCurve::Linear );
    pAnimation->start();
}


void pseven::on_pBtnEnter_clicked()
{
    slotBtnEnter();
}
*/
