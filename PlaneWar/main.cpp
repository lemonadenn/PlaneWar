#include "widget.h"
#include <QApplication>
#include <QResource>
#include <QWidget>
#include<QTimer>
#include<QLabel>
#include<QString>
#include<QLayout>

#include "config.h"

int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    //注册外部的rcc资源
    QResource::registerResource(GAME_SRC_PATH);
    QResource::registerResource(GAME_RES_PATHONE);
    QResource::registerResource(GAME_RES_PATHTWO);
    QResource::registerResource(GAME_RES_PATHTHREE);
    Widget w;


    w.show();



    return a.exec();
}
