#ifndef BUFF_H
#define BUFF_H
#include <QPixmap>
#include <QRect>
#include "heroplane.h"
#include "config.h"

class Buff
{
public:
    Buff();
    void updatePosition(); //更新位置
    void strengthen(HeroPlane *hero); //强化飞机
    void addHp(HeroPlane *hero);
public:
    QPixmap buff_pic; //buff图标
    double m_X, m_Y;
    QRect m_rect;
    bool m_free;
    double m_speed;
};

#endif // BUFF_H
