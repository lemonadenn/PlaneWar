#include "hppotion.h"

//初始化
hp_potion::hp_potion(){

    m_heart.load(HPPOTION_PATH);
    m_rect.setWidth(m_heart.width());
    m_rect.setHeight(m_heart.height());

    remain_time = HPPOTION_REMAIN_TIME;
    m_free = true;
    flag = true;
    flash_recorder = 0;
    m_x = rand() % (GAME_WIDTH - m_heart.width());
    m_y = rand() % (GAME_HEIGHT - m_heart.height()- GAME_HEIGHT / 2) + GAME_HEIGHT / 2;
    m_rect.moveTo(m_x, m_y);

}

void hp_potion::refresh()      //刷新血包
{
    m_x = rand() % (GAME_WIDTH - m_heart.width());
    m_y = rand() % (GAME_HEIGHT - m_heart.height()- GAME_HEIGHT / 2) + GAME_HEIGHT / 2;
    m_rect.moveTo(m_x, m_y);
    remain_time = HPPOTION_REMAIN_TIME;
    flash_recorder = 0;
    flag = true;
}
