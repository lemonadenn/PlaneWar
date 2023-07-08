#include "bomb.h"
#include "config.h"
bomb::bomb()
{
    //将所有的爆炸资源放入数组中
    //用迭代器it读取文件夹中的每个路径；
    QString directoryPath = BOMB_DIR;
        QDirIterator it(directoryPath, QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        QString str = it.next();
        m_pixArr.push_back(QPixmap(str));
    }
    maxind = m_pixArr.length();



    //坐标
    m_x=0;
    m_y=0;

    //空闲状态
    m_Free=true;

    //当前播放图片下标
    m_index=0;

    //播放爆炸间隔记录
    m_Recoder=0;
}

void bomb::updateInfo()
{
    if(m_Free)
        return;
    m_Recoder++;
    //如果记录爆炸的实际未达到爆炸间隔，不需要切图，直接return
    if(m_Recoder<BOMB_INTERVAL)
        return;
    //重置记录
    m_Recoder=0;
    //切换爆炸播放的图片下标
    m_index++;
    if(m_index>maxind - 1)
    {
        m_index=0;
        m_Free=true;//播放爆炸效果完成
    }

}
