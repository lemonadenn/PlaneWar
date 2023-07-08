#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QPixmap>
#include <QRect>
class enemyPlane
{
public:
    enemyPlane();

    //更新敌机坐标
    void updatePosition();
    //敌机对象
    QPixmap m_enemy;
    //敌机坐标位置
    double m_x;
    double m_y;
    //敌机的边框，便于碰撞检测
    QRect m_Rect;
    //状态
    bool m_Free;
    //敌机速度
    double m_speed;

};

#endif // ENEMYPLANE_H
