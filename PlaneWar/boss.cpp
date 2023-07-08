#include "boss.h"

Boss::Boss()
{
    boss_mode.load(BOSS_PATH);
    m_X = m_Y = 0;
    m_free = true;
    m_come = false;
    defeated = false;
    move_recorder = 0;
    recorder1 = remain_time =0;
    shoot_type = 0;
    hp = BOSS_HP;
    m_speed = BOSS_SPEED;
    m_rect.setWidth(boss_mode.width());
    m_rect.setHeight(boss_mode.height());
    m_rect.moveTo(m_X,m_Y);
    for(int i=0;i<BOSS_TRACE_BULLET_NUM;i++)
    {
        trace_bullets[i].mode.load(BOSS_TRACE_BULLET_PATH);
        trace_bullets[i].rect.setWidth(trace_bullets[i].mode.width());
        trace_bullets[i].rect.setHeight(trace_bullets[i].mode.height());
        trace_bullets[i].speed = BOSS_BULLET_SPEED;
    }
    for(int i=0;i<BOSS_SPRINKLER_BULLET_NUM;i++)
    {
        sprinkler_bullets[i].mode.load(BOSS_SPRINKLER_BULLET_PATH);
        sprinkler_bullets[i].mode = sprinkler_bullets[i].mode.scaled(16, 16);
        sprinkler_bullets[i].rect.setWidth(sprinkler_bullets[i].mode.width());
        sprinkler_bullets[i].rect.setHeight(sprinkler_bullets[i].mode.height());
        trace_bullets[i].speed = BOSS_SPRINKLER_SPEED;
    }
}

void Boss::updatePosition()
{
    const int dir[9]={0,-1,0,1,0,1,0,-1,0};
    if(m_free) return;
    if(defeated){
        m_Y -= 1;
        return;        //缓慢退场；
    }
    if(m_Y<=4) m_Y+=1; //缓慢出场
    else{
        if(shoot_type == 2) return;
        move_recorder++;
        double d=m_speed*dir[move_recorder/MOVE_INTERVAL];
        if(move_recorder==8*MOVE_INTERVAL) move_recorder=0;
        if(d<0&&m_X<=0.05*GAME_WIDTH||d>0&&m_X+m_rect.width()>=0.95*GAME_WIDTH) return;
        m_X+=d;
    }
    m_rect.moveTo(m_X,m_Y);
}

//random shoot
void Boss::shoot_1()
{
    recorder1++;
    if(recorder1<BOSS_BULLET_INTERVAL) return;
    recorder1=0;
    for(int i=0;i<BOSS_BULLET_NUM;i++){
        if(linear_bullets[i].free){
            linear_bullets[i].free = false;
            linear_bullets[i].angle = ((rand()%50)+1)*0.01*PI+0.25*PI; //45°~135°随机
            linear_bullets[i].X = ((rand()%50+1)*0.02*0.6+0.2)*boss_mode.width();
            linear_bullets[i].Y = m_Y+boss_mode.height();
            linear_bullets[i].rect.moveTo(linear_bullets[i].X,linear_bullets[i].Y);
            break;
        }
    }
}

//trace shoot
void Boss::shoot_2()
{
    recorder1++;
    if(recorder1<BOSS_TRACE_INTERVAL) return;
    recorder1=0;
    for(int i=0;i<BOSS_TRACE_BULLET_NUM;i++){
        if(trace_bullets[i].free){
            trace_bullets[i].free = false;
            trace_bullets[i].trace_recorder = 0;
            trace_bullets[i].X = m_X+0.5*boss_mode.width()-0.5*sprinkler_bullets[i].mode.width();
            trace_bullets[i].Y = m_Y+boss_mode.height();
            trace_bullets[i].rect.moveTo(trace_bullets[i].X,trace_bullets[i].Y);
            break;
        }
    }
}

//sprinkler shoot
void Boss::shoot_3()
{
    recorder1++;
    if(recorder1<BOSS_SPRINKLER_INTERVAL) return;
    recorder1=0;

    //随机2~8等分
    int split_num = (rand()%7)+2;
    int haveFound = 0;
    for(int i=0;i<BOSS_SPRINKLER_BULLET_NUM;i++){
        if(sprinkler_bullets[i].free){
            sprinkler_bullets[i].free = false;
            sprinkler_bullets[i].X = m_X+0.5*boss_mode.width()-0.5*sprinkler_bullets[i].mode.width();
            sprinkler_bullets[i].Y = m_Y+boss_mode.height();
            sprinkler_bullets[i].rect.moveTo(sprinkler_bullets[i].X,sprinkler_bullets[i].Y);
            sprinkler_bullets[i].angle = (30+(120/split_num)*haveFound)*PI/180;
            haveFound++;
            if(haveFound==split_num+1) break;
        }
    }
}

//overall shoot
void Boss::shoot()
{
    const int shoot_time[]={BOSS_RANDOM_SHOOT_TIME,
                             BOSS_TRACE_SHOOT_TIME,
                             BOSS_SPRINKLER_SHOOT_TIME};
    remain_time++;
    if(remain_time == shoot_time[shoot_type])
    {
        remain_time = 0;
        shoot_type = rand()%3;
        recorder1 = 0;
    }
    switch (shoot_type) {
    case 0:
        shoot_1();
        break;
    case 1:
        shoot_2();
        break;
    case 2:
        shoot_3();
        break;
    default:
        break;
    }
}
