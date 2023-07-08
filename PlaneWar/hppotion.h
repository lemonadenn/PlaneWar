#ifndef HPPOTION_H
#define HPPOTION_H

#include "config.h"
#include <QPixmap>
#include <QRect>

class hp_potion{
public:
    QPixmap m_heart;
    //存在时间；
    int remain_time;
    //出现位置
    int m_x;
    int m_y;
    QRect m_rect;


    bool m_free;

    hp_potion();
    void refresh();
    //是否出现，用于绘制闪烁；
    bool flag;
    int flash_recorder;
};

#endif // HPPOTION_H
