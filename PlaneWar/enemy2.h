#ifndef ENEMY2_H
#define ENEMY2_H


#include <QPixmap>
#include <QRect>
#include "config.h"



class fireball{
public:
    QPixmap ball;
    int m_x;
    int m_y;
    QRect m_Rect;
    bool m_Free;
    //子弹速度
    int speed_x;
    int speed_y;
    fireball();
    void updatePosition();
};



class enemy2{
public:
    //更新敌机坐标
    void updatePosition();
    //敌机对象
    QPixmap m_enemy;
    //敌机坐标位置
    int m_x;
    int m_y;
    //敌机的边框，便于碰撞检测
    QRect m_Rect;
    //状态
    bool m_Free;
    //敌机速度
    int m_speed;

    enemy2();
    //敌机血量
    int hp;
};

#endif // ENEMY2_H
