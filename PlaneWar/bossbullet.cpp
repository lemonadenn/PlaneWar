#include "bossbullet.h"

BossBullet::BossBullet()
{
    mode.load(BOSS_BULLET_PATH);
    free = true;
    X = Y = 0;
    speed = BOSS_BULLET_SPEED;
    angle = 0.5*PI;
    rect.setWidth(mode.width());
    rect.setHeight(mode.height());
    rect.moveTo(X,Y);
    trace_recorder = 0;
}

void BossBullet::linear_move(double theta)
{
    if(free) return;
    X += speed*cos(theta);
    Y += speed*sin(theta);
    rect.moveTo(X,Y);
    if(X+mode.width()<0 || X>GAME_WIDTH || Y>GAME_HEIGHT) free=true;
}



void BossBullet::trace_move(double tX, double tY)
{
    if(free) return;
    trace_recorder++;
    //追踪弹超出存在时间则消失
    if(trace_recorder>=TRACE_EXIST_TIME)
    {
        free = true;
        trace_recorder=0;
        return;
    }
    //用向量实时跟踪
    if(X-tX!=0||Y-tY!=0)
    {
        double dY = tY-Y;
        double dX = tX-X;
        double rate = BOSS_BULLET_SPEED/sqrt(dX*dX+dY*dY);
        X += rate*dX;
        Y += rate*dY;
    }
    rect.moveTo(X,Y);
    if(X+mode.width()<0 || X>GAME_WIDTH || Y>GAME_HEIGHT) free = true;
}


