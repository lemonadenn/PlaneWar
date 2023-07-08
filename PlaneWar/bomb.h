#ifndef BOMB_H
#define BOMB_H


#include "config.h"
#include <QPixmap>
#include <QVector>
#include <QDir>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QDirIterator>


class bomb
{
public:
    bomb();

    //更新爆炸信息
    void updateInfo();

    //放置爆炸资源的数组
    QVector<QPixmap> m_pixArr;

    //爆炸坐标
    int m_x;
    int m_y;

    //爆炸状态
    bool m_Free;

    //爆炸切图的时间间隔
    int m_Recoder;

    //爆炸时加载的图片下标
    int m_index;

    //爆炸的最大图片数；
    int maxind;

};

#endif // BOMB_H
