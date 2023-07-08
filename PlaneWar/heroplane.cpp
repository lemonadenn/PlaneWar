#include "heroplane.h"
#include "config.h"
#include "bullet.h"

HeroPlane::HeroPlane()
{
    m_plane.load(HERO_PATH);
    m_plane = m_plane.scaled(80, 54.4w, Qt::KeepAspectRatioByExpanding);
    heart_pic.load(HEART_PATH); //加载生命值
    //飞机初始位置
    m_X = GAME_WIDTH*0.5-m_plane.width()*0.5;
    m_Y = GAME_HEIGHT-m_plane.height();
    //初始化矩形边框
    m_rect.setWidth(m_plane.width());
    m_rect.setHeight(m_plane.height());
    m_rect.moveTo(m_X,m_Y);
    m_recorder = 0;
    hp = HERO_HP; //飞机初始生命值
    shoot_level=1; //初始时一次发射1个子弹
    buff_remain_time=0; //初始时没有Buff，时间自然是0
    for(int i=0;i<30;i++){
        super_bullets[i].updateStatus(SUPER_BULLET_PATH);
    }
    flag = true;
    flash_recorder = 0;
}

void HeroPlane::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;
    m_rect.moveTo(x,y);
}

//更新绘制状态
void HeroPlane::refresh()
{
    if(flash_recorder){
        flash_recorder--;
        if(flash_recorder % HERO_FLASH_INTERVAL == 0){
            if(flag){
                flag = false;
            }else{
                flag = true;
            }
        }
    }else{
        flag = true;
    }

}

void HeroPlane::shoot()
{
    if(buff_remain_time>0) buff_remain_time-=1;
    //buff剩余时间结束时, 子弹数目降级
    if(buff_remain_time==0){
        if(shoot_level >=2) {shoot_level-=1; buff_remain_time-=1;} //等于1时就不降级了
    }

    m_recorder++; //累加, 间隔一定时间后发射子弹
    //如果为达到发射间隔, 直接return
    if(m_recorder < BULLET_INTERVAL) return;
    m_recorder=0;

    //发射子弹
    int k=0;
    int b[3]; //找子弹，把下标记录在b中
    switch (shoot_level) {
    case 1:
        for(int i = 0 ; i < BULLET_NUM;i++)
        {
            //如果是空闲的子弹进行发射
            if(m_bullets[i].m_free)
            {
                //将改子弹空闲状态改为假
                m_bullets[i].m_free = false;
                //设置发射的子弹坐标
                m_bullets[i].m_X = m_X + m_plane.width()*0.5 - m_bullets[i].m_bullet.width()*0.5;
                m_bullets[i].m_Y = m_Y - 25 ;
                break;
            }
        }

        break;
    case 2:
        //找两颗free的子弹, 并记录
        for(int i=0; i<BULLET_NUM;i++){
            if(k==2) break;
            if(m_bullets[i].m_free) {b[k++]=i; m_bullets[i].m_free=false;}
        }
        m_bullets[b[0]].m_X = m_X+m_plane.width()*0.5-m_bullets[b[0]].m_bullet.width();
        m_bullets[b[1]].m_X = m_X+m_plane.width()*0.5;
        m_bullets[b[0]].m_Y = m_bullets[b[1]].m_Y = m_Y-25;

        break;
    case 3:
        //找三颗free的子弹, 并记录
        for(int i=0; i<BULLET_NUM;i++){
            if(k==3) break;
            if(m_bullets[i].m_free){
                b[k++]=i; m_bullets[i].m_free=false;
                m_bullets[i].m_Y = m_Y-25;
            }
        }
        m_bullets[b[0]].m_X = m_X+m_plane.width()*0.5-m_bullets[b[0]].m_bullet.width()*0.5;
        m_bullets[b[1]].m_X = m_X+m_plane.width()*0.5-m_bullets[b[1]].m_bullet.width()*1.5;
        m_bullets[b[2]].m_X = m_X+m_plane.width()*0.5+m_bullets[b[2]].m_bullet.width()*0.5;

        break;
    case 4:
        for(int i=0; i<30;i++){
            if(super_bullets[i].m_free){
                //将改子弹空闲状态改为假
                super_bullets[i].m_free = false;
                //设置发射的子弹坐标
                super_bullets[i].m_X = m_X + m_plane.width()*0.5 - super_bullets[i].m_bullet.width()*0.5;
                super_bullets[i].m_Y = m_Y - 25 ;
                break;
            }
        }
    default:
        break;
    }
}
