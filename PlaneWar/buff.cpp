#include "buff.h"


Buff::Buff()
{
    buff_pic.load(BUFF_PATH);
    m_X = m_Y = -buff_pic.height();//设成多少关系不大

    m_rect.setWidth(buff_pic.width());
    m_rect.setHeight(buff_pic.height());
    m_rect.moveTo(m_X,m_Y);

    m_free = true; //初始时所有buff都可用
    m_speed = BUFF_SPEED;
}

void Buff::updatePosition()
{
    if(m_free) return; //free状态的buff不会出现在场景中
    m_Y+=m_speed;
    m_rect.moveTo(m_X,m_Y);

    //飞出屏幕后变为free
    if(m_Y >= GAME_HEIGHT + m_rect.height()) m_free=true;
}

void Buff::strengthen(HeroPlane *hero)
{
    hero->buff_remain_time=BUFF_REMAIN_TIME; //刷新buff剩余时间
    if(hero->shoot_level<4) hero->shoot_level+=1; // 射出子弹数加一
}

void Buff::addHp(HeroPlane *hero)
{
    if(hero->hp < HERO_HP) hero->hp++;
}

