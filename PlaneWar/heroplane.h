#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include <QRect>
#include <QSound>
#include "bullet.h"

class HeroPlane
{
public:
    HeroPlane();

    void shoot(); //发射子弹
    void setPosition(int, int); //设置飞机位置
public:
    QPixmap m_plane; // 飞机图片
    QPixmap heart_pic; //爱心图片，显示当前生命值
    double m_X,m_Y; //飞机位置坐标
    QRect m_rect; //飞机的矩形边框，用于碰撞检测
    Bullet m_bullets[BULLET_NUM]; //弹匣
    Bullet super_bullets[30]; //超级子弹
    int m_recorder; //shoot间隔记录
    int hp; //飞机生命值
    int shoot_level; //1,2,3分别表示一次发射1,2,3个子弹
    int buff_remain_time; //buff剩余持续时间

    //是否出现，用于绘制闪烁；
    bool flag;
    int flash_recorder;
    //更新闪烁状态；
    void refresh();
};

#endif // HEROPLANE_H
