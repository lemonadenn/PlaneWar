#include "map.h"
#include "config.h"

Map::Map()
{
    //初始化加载地图对象
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);


    m_map1 = m_map1.scaled(GAME_WIDTH, GAME_HEIGHT, Qt::KeepAspectRatioByExpanding);  //将图像放缩成指定大小；
    m_map2 = m_map2.scaled(GAME_WIDTH, GAME_HEIGHT, Qt::KeepAspectRatioByExpanding);

    //设置坐标
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;


    //设置滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    //处理第一张图片滚动
    m_map1_posY += m_scroll_speed;
    if(m_map1_posY >= 0)
    {
        m_map1_posY = -GAME_HEIGHT;
    }

    //处理第二张图片滚动
    m_map2_posY += m_scroll_speed;
    if(m_map2_posY >= GAME_HEIGHT)
    {
        m_map2_posY = 0;
    }

}
