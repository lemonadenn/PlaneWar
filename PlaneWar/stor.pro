#-------------------------------------------------
#
# Project created by QtCreator 2023-07-04T01:42:48
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stor
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    pone.cpp \
    ptwo.cpp \
    pthree.cpp \
    pfour.cpp \
    pfive.cpp \
    psix.cpp \
    pseven.cpp \
    peight.cpp \
    pnine.cpp \
    pten.cpp \
    map.cpp \
    heroplane.cpp \
    bullet.cpp \
    buff.cpp \
    enemyplane.cpp \
    bomb.cpp \
    boss.cpp \
    bossbullet.cpp \
    enemy2.cpp \
    hppotion.cpp\
    mainscene.cpp

HEADERS  += widget.h \
    pone.h \
    ptwo.h \
    config.h \
    pthree.h \
    pfour.h \
    pfive.h \
    psix.h \
    pseven.h \
    peight.h \
    pnine.h \
    pten.h \
    map.h \
    config.h \
    heroplane.h \
    bullet.h \
    buff.h \
    enemyplane.h \
    bomb.h \
    boss.h \
    bossbullet.h \
    enemy2.h \
    hppotion.h\
    mainscene.h

FORMS    += widget.ui \
    pone.ui \
    ptwo.ui \
    pthree.ui \
    pfour.ui \
    pfive.ui \
    psix.ui \
    pseven.ui \
    peight.ui \
    pnine.ui \
    pten.ui

RESOURCES += \
    gamestart.qrc \
    backgroundone.qrc \
    story.qrc \
    win.qrc

DISTFILES += \
    ui/YOUWIN (2).png \
    ui/YOUWIN (2).png \
    ui/YOUWIN (2).png \
    ui/YOUWIN (2).png

