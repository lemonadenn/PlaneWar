#include "bullet.h"

Bullet::Bullet()
{
    m_bullet.load(BULLET_PATH);

    m_X = GAME_WIDTH*0.5-m_bullet.width()*0.5;
    m_Y = GAME_HEIGHT;

    m_free = true;
    m_speed = BULLET_SPEED;

    m_rect.setWidth(m_bullet.width());
    m_rect.setHeight(m_bullet.height());
    m_rect.moveTo(m_X,m_Y);
}

void Bullet::updatePosition()
{
    if(m_free) return; //子弹空闲,不需要计算坐标
    m_Y-=m_speed;
    m_rect.moveTo(m_X,m_Y);

    if(m_Y <= -m_rect.height()) m_free=true; //子弹飞出地图后其模型可再次使用

}

void Bullet::updateStatus(QString path)
{
    m_bullet.load(path);
    m_rect.setWidth(m_bullet.width());
    m_rect.setHeight(m_bullet.height());
    m_rect.moveTo(m_X,m_Y);
}
