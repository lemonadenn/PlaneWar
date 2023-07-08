#include "enemyplane.h"
#include "config.h"
enemyPlane::enemyPlane()
{
    //加载敌机资源
    m_enemy.load(ENEMY_PATH);
    //敌机初始位置
    m_x=0;
    m_y=0;

    //敌机状态
    m_Free=true;

    //敌机速度
    m_speed=ENEMY_SPEED;
    //敌机边框
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_x,m_y);
}
//更新敌机坐标
void enemyPlane::updatePosition()
{
    //空闲状态的敌机不需要计算坐标
    if(m_Free)
        return ;
    m_y+=m_speed;
    m_Rect.moveTo(m_x,m_y);
    //如果超出屏幕 重置空闲状态
    if(m_y>=GAME_HEIGHT+m_Rect.height())
        m_Free=true;
}
