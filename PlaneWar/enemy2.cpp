#include "enemy2.h"
#include "config.h"




enemy2::enemy2()
{
    //加载敌机资源
    m_enemy.load(ENEMY2_PATH);
    //敌机初始位置
    m_x=0;
    m_y=0;
    hp = 3;
    //敌机状态
    m_Free=true;

    //敌机速度
    m_speed=ENEMY2_SPEED;
    //敌机边框
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_x,m_y);
}
//更新敌机坐标
void enemy2::updatePosition()
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

fireball::fireball(){
    m_x = m_y = 0;
    ball.load(FIREBALL_PATH);
    ball = ball.scaled(BALL_SIZE, BALL_SIZE, Qt::KeepAspectRatioByExpanding);

    m_Rect.setWidth(ball.width());
    m_Rect.setHeight(ball.height());
    m_Rect.moveTo(m_x,m_y);
    speed_x = speed_y = 0;
    m_Free = true;
}

void fireball::updatePosition(){
    if(m_Free){
        return;
    }
    m_y += speed_y;
    m_x += speed_x;
    m_Rect.moveTo(m_x, m_y);
    //超出屏幕，重置状态
    if(m_y >=GAME_HEIGHT+m_Rect.height() || m_y <= -m_Rect.height())
        m_Free = true;
    if(m_x <= -m_Rect.width() || m_x >= GAME_WIDTH + m_Rect.width())
        m_Free = true;
}
