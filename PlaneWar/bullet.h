#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>
#include <QString>

class Bullet
{
public:
    Bullet();

    void updatePosition(); //更新子弹坐标

    void updateStatus(QString path);

public:
    QPixmap m_bullet; //子弹图片
    double m_X,m_Y; //坐标
    double m_speed; //速度
    bool m_free; //是否可用
    QRect m_rect; // 矩形边框
};

#endif // BULLET_H
