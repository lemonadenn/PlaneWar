#ifndef BOSS_H
#define BOSS_H
#include "config.h"
#include <QPixmap>
#include "bossbullet.h"
class Boss
{
public:
    Boss();
    void updatePosition();
    void shoot_1(); //随机发射子弹
    void shoot_2(); //追踪弹
    void shoot_3(); //散花
    void shoot();
public:
    QPixmap boss_mode;
    double m_X,m_Y;
    double m_speed;
    int hp;
    int move_recorder;
    bool m_free;
    bool m_come;
    bool defeated;
    QRect m_rect;
    BossBullet linear_bullets[BOSS_BULLET_NUM];
    BossBullet trace_bullets[BOSS_TRACE_BULLET_NUM];
    BossBullet sprinkler_bullets[BOSS_SPRINKLER_BULLET_NUM];
    int remain_time; //记录当前弹幕持续时间
    int recorder1; //记录子弹发射间隔
    int shoot_type; //0,1,2分别代表random,trace,sprinkler
};

#endif // BOSS_H
