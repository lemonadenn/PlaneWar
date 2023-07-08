#ifndef BOSSBULLET_H
#define BOSSBULLET_H
#include <QPixmap>
#include <QRect>
#include <QtMath>
#include "config.h"


class BossBullet
{
public:
    BossBullet();
    void linear_move(double theta); //直线移动, theta是与x轴正方向的夹角
    void trace_move(double tX, double tY); //追踪移动

public:
    QPixmap mode;
    double X,Y;
    bool free;
    double speed;
    double angle;
    QRect rect;
    int trace_recorder;//追踪弹已存在时间
};

#endif // BOSSBULLET_H
