#include "mainscene.h"
#include "config.h"
#include "pnine.h"



MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
/*************键盘，不用管*********************/
keyRespondTimer = new QTimer(this);
connect(keyRespondTimer, &QTimer::timeout, this, &MainScene::slotTimeOut);
/*************键盘，不用管*********************/

    //初始化场景
    initScene();
}

MainScene::~MainScene()
{

}

void MainScene::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));

    m_Timer.setInterval(GAME_RATE);
    buff_recorder = 0;
    hpbuff_recorder = 0;
    m_recorder = 0;
    boss_recorder = 0;
    srand((unsigned int)time(NULL));//随机数种子，用于敌机和buff出现位置的随机化
    for(int i=0;i<BUFF_NUM;i++)
    {
        hpbuffs[i].buff_pic.load(HEART_PATH);
        hpbuffs[i].m_X = hpbuffs[i].m_Y = -hpbuffs[i].buff_pic.height();//设成多少关系不大

        hpbuffs[i].m_rect.setWidth(hpbuffs[i].buff_pic.width());
        hpbuffs[i].m_rect.setHeight(hpbuffs[i].buff_pic.height());
        hpbuffs[i].m_rect.moveTo(hpbuffs[i].m_X,hpbuffs[i].m_Y);
    }


    //start_button = new QPushButton("开始游戏", this); //开始游戏按钮设置;

    //记分板配置；
    score = 0;
    QFont font1;     //记分板字体；
    font1.setFamily("宋体");
    font1.setBold(true);
    font1.setItalic(true);
    font1.setPixelSize(20);
    QPalette pe;
    pe.setColor(QPalette::WindowText, Qt::white);//设置颜色
    scoreboard = new QLabel(this);
    scoreboard->setFont(font1);
    scoreboard->setPalette(pe);
    scoreboard->setText("Score: 0"); // 初始得分为0
    scoreboard->setGeometry(10, 20, 150, 50); // 设置 QLabel 的位置和大小
    scoreboard->setStyleSheet("background-color: transparent;");
    scoreboard->show();
    playGame();
}



void MainScene::playGame()
{

    m_Timer.start();
    //播放音效
    player->setMedia(QUrl::fromLocalFile(SOUND_BACKGROUND1));
    player->play();
    //监听定时器，最后一个参数是一个lambda函数

    bool boss_appear = false;

    connect(&m_Timer,&QTimer::timeout,[=]()mutable
    {

        QApplication::processEvents();
        //更新场景中对象的位置
        updatePosition();
        //重新绘制图片
        update();
        //碰撞检测
        collisionDetect();
        //更新玩家飞机的绘制状态
        m_hero.refresh();

        if(score <= SCORE_LEVEL){
            enemyToScene();     //敌机出现；
            enemy2ToScene();         //2号敌机出现；
            hppotionToScene();        //血包出现；
        }
        //分数指标达到 ，解锁boss；
        else{
            if(!boss_appear){
                boss_appear = true;
                player->stop();
                player->setMedia(QUrl::fromLocalFile(SOUND_BACKGROUND2));
                player->play();
            }
            //buff出现
            buffToScene();
            hpbuffToScene();
            //boss出现
            bossToScene();
        }
        gameover();
    });
}


void MainScene::boss_defeated(){        //boss被打跑游戏胜利；
    pnine *w=new pnine();
    w->show();
    m_Timer.stop();
    this->close();
}


//对象位置的更新都在这儿
void MainScene::updatePosition()
{
    // 更新地图坐标
    m_map.mapPosition();
    // 发射子弹
    m_hero.shoot();
    // boss发射子弹
    if(boss.m_Y>=4&&!boss.m_free) boss.shoot();
    //更新子弹坐标
    for(int i = 0 ; i < BULLET_NUM; i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!m_hero.m_bullets[i].m_free) m_hero.m_bullets[i].updatePosition();
    }
    for(int i=0; i<30;i++)
    {
        if(!m_hero.super_bullets[i].m_free) m_hero.super_bullets[i].updatePosition();
    }
    //更新buff坐标
    for(int i = 0; i < BUFF_NUM; i++)
    {
        if(!buffs[i].m_free) buffs[i].updatePosition();
    }
    for(int i = 0; i < BUFF_NUM; i++)
    {
        if(!hpbuffs[i].m_free) hpbuffs[i].updatePosition();
    }
    //更新enemyplane坐标；
    for(int i = 0; i < ENEMY_NUM; i++){
        m_enemys[i].updatePosition();
    }
    //更新enemy2坐标
    for(int i = 0; i < ENEMY2_NUM; i++){
        m2_enemys[i].updatePosition();
    }
    //更新火球坐标；
    for(int i = 0; i < FIREBALL_NUM; i++){
        m_fireballs[i].updatePosition();
    }
    //更新boss坐标
    if(!boss.m_free) boss.updatePosition();
    //更新boss的子弹的坐标
    for(int i=0;i<BOSS_BULLET_NUM;i++)
    {
        if(!boss.linear_bullets[i].free) boss.linear_bullets[i].linear_move(boss.linear_bullets[i].angle);
    }
    for(int i=0;i<BOSS_TRACE_BULLET_NUM;i++)
    {
        if(!boss.trace_bullets[i].free) boss.trace_bullets[i].trace_move(m_hero.m_X,m_hero.m_Y);
    }
    for(int i=0;i<BOSS_SPRINKLER_BULLET_NUM;i++)
    {
        if(!boss.sprinkler_bullets[i].free) boss.sprinkler_bullets[i].linear_move(boss.sprinkler_bullets[i].angle);
    }
    //计算爆炸的播放图片
    for(int i=0;i<BOMB_NUM;i++)
    {
       if(m_bombs[i].m_Free==false)
       {
           m_bombs[i].updateInfo();
       }
    }
    //boss被击败
    if(boss.hp<=0 && boss.m_free == false)
    {
        boss.defeated=true;

    }
}



//buff出现
void MainScene::buffToScene()
{
    buff_recorder++;
    if(buff_recorder < BUFF_INTERVAL) return;

    buff_recorder=0;
    for(int i = 0; i < BUFF_NUM; i++)
    {
        if(buffs[i].m_free)
        {
            buffs[i].m_free = false;
            buffs[i].m_X = rand()%(GAME_WIDTH-buffs[i].m_rect.width());
            buffs[i].m_Y = -buffs[i].m_rect.height();
            break;
        }
    }
}

//血包
void MainScene::hppotionToScene(){
    if(m_hppotion.m_free){
        potion_recorder++;
        if(potion_recorder < HPPOTION_INTERVAL) return;

        potion_recorder = rand() % 500;

        m_hppotion.m_free = false;
        m_hppotion.refresh();
    }else{
        m_hppotion.remain_time--;
        if(m_hppotion.remain_time <= 0){
            m_hppotion.m_free = true;
            return;
        }

        //持续时间剩余30%内，血包开始闪烁；
        if(m_hppotion.remain_time <= HPPOTION_REMAIN_TIME * 0.3){
            m_hppotion.flash_recorder++;
            if(m_hppotion.flash_recorder < FLASH_INTERVAL) return;

            m_hppotion.flash_recorder = 0;
            if(m_hppotion.flag){
                m_hppotion.flag = false;
            }else{
                m_hppotion.flag = true;
            }
        }
    }
}

//2号敌机被击中时会射出复仇的火球
void MainScene::shoot_fireball(int k){
    for(int i = 0; i < FIREBALL_NUM; i++){
        if(!m_fireballs[i].m_Free) continue;

        m_fireballs[i].m_Free = false;
        m_fireballs[i].m_x = m2_enemys[k].m_x;
        m_fireballs[i].m_y = m2_enemys[k].m_y;
        m_fireballs[i].speed_x = (m_hero.m_X - m2_enemys[k].m_x) * FIREBALL_SPEED;
        m_fireballs[i].speed_y = (m_hero.m_Y - m2_enemys[k].m_y) * FIREBALL_SPEED;
        if(m_fireballs[i].speed_x == 0) m_fireballs[i].speed_x = 1;
        if(m_fireballs[i].speed_y == 0) m_fireballs[i].speed_y = 1;
        m_fireballs[i].speed_y += MAP_SCROLL_SPEED;
        if(m_fireballs[i].speed_y > 8) m_fireballs[i].speed_y = 8;
        break;
    }
}


//hpbuff出现
void MainScene::hpbuffToScene()
{
    hpbuff_recorder++;
    if(hpbuff_recorder < HP_BUFF_INTERVAL) return;

    hpbuff_recorder=0;
    for(int i = 0; i < BUFF_NUM; i++)
    {
        if(hpbuffs[i].m_free)
        {
            hpbuffs[i].m_free = false;
            hpbuffs[i].m_X = rand()%(GAME_WIDTH-hpbuffs[i].m_rect.width());
            hpbuffs[i].m_Y = -hpbuffs[i].m_rect.height();
            break;
        }
    }
}

//boss出现
void MainScene::bossToScene()
{
    if(boss.m_come) return;
    boss_recorder++;
    if(boss_recorder<BOSS_INTERVAL) return;

    boss.m_come = true;
    boss.m_free = false;
    boss.m_X = GAME_WIDTH*0.5-boss.m_rect.width()*0.5;
    boss.m_Y = -boss.m_rect.height();
}

//碰撞检测
void MainScene::collisionDetect()
{
    //buff与hero碰撞
    for(int i=0; i<BUFF_NUM; i++)
    {
        if(buffs[i].m_free) continue;
        //buff与玩家飞机碰撞
        if(buffs[i].m_rect.intersects(m_hero.m_rect))
        {
            buffs[i].strengthen(&m_hero);
            QSound::play(SOUND_UPDATE);
            buffs[i].m_free = true;
        }
    }
    //hpbuff与hero碰撞
    for(int i=0; i<BUFF_NUM; i++)
    {
        if(hpbuffs[i].m_free) continue;
        //buff与玩家飞机碰撞
        if(hpbuffs[i].m_rect.intersects(m_hero.m_rect))
        {
            hpbuffs[i].addHp(&m_hero);
            hpbuffs[i].m_free = true;
            QSound::play(SOUND_BLOOD);
        }
    }

    //fireball 与玩家飞机的碰撞
    for(int i = 0; i < FIREBALL_NUM; i++){
        if(m_fireballs[i].m_Free) continue;
        if(m_fireballs[i].m_Rect.intersects(m_hero.m_rect)){
            m_fireballs[i].m_Free = true;
            if(!m_hero.flash_recorder){
                m_hero.hp--;
                QSound::play(SOUND_HERT);
                m_hero.flash_recorder += HERO_FLASH_TIME;
            }
        }
    }
    //血包与玩家的碰撞
    if(!m_hppotion.m_free && m_hppotion.m_rect.intersects(m_hero.m_rect)){
        m_hppotion.m_free = true;
        if(m_hero.hp < 10){
            m_hero.hp++;
            QSound::play(SOUND_BLOOD);
        }
    }
    //遍历出场敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //空闲飞机则执行下一次循环
        if(m_enemys[i].m_Free)
        {
            continue;
        }
        //如果飞机与敌机相撞则飞机坠毁，将状态设置为空闲
        if(m_enemys[i].m_Rect.intersects(m_hero.m_rect))
        {
            if(!m_hero.flash_recorder){
                m_hero.hp--;
                QSound::play(SOUND_HERT);
                m_hero.flash_recorder += HERO_FLASH_TIME;
            }
            m_enemys[i].m_Free = true;
            for(int k=0;k<BOMB_NUM;k++)
            {
                if(m_bombs[k].m_Free)
                {
                    //播放爆炸音效
                    QSound::play(SOUND_BOMB);
                    //空闲的爆炸，可以播放
                    m_bombs[k].m_Free=false;
                    //更新爆炸坐标
                    m_bombs[k].m_x=m_hero.m_X;
                    m_bombs[k].m_y=m_hero.m_Y;
                    break;
                }

            }

        }
        //遍历所有非空闲子弹
        for(int j=0;j<BULLET_NUM;j++)
        {
            //空闲子弹则执行下一次循环
            if(m_hero.m_bullets[j].m_free)
            {
                continue;
            }

            //如果子弹边框和敌机边框相交则说明发生碰撞，则将他们状态设置为空闲
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_rect))
            {
                m_enemys[i].m_Free=true;
                m_hero.m_bullets[j].m_free=true;
                score += 10;
                //播放爆炸效果
                for(int k=0;k<BOMB_NUM;k++)
                {
                    if(m_bombs[k].m_Free)
                    {
                        //播放爆炸音效
                        QSound::play(SOUND_BOMB);
                        //空闲的爆炸，可以播放
                        m_bombs[k].m_Free=false;
                        //更新爆炸坐标
                        m_bombs[k].m_x=m_enemys[i].m_x;
                        m_bombs[k].m_y=m_enemys[i].m_y;
                        break;
                    }
                }
            }

        }

    }
    //遍历enemy2
    for(int i=0;i<ENEMY2_NUM;i++)
    {
        //空闲飞机则执行下一次循环
        if(m2_enemys[i].m_Free)
        {
            continue;
        }
        //如果飞机与敌机相撞则飞机坠毁，将状态设置为空闲
        if(m2_enemys[i].m_Rect.intersects(m_hero.m_rect))
        {
            if(!m_hero.flash_recorder){
                m_hero.hp--;
                QSound::play(SOUND_HERT);
                m_hero.flash_recorder += HERO_FLASH_TIME;
            }
            m2_enemys[i].m_Free = true;
            for(int k=0;k<BOMB_NUM;k++)
            {
                if(m_bombs[k].m_Free)
                {
                    //播放爆炸音效
                    QSound::play(SOUND_BOMB);
                    //空闲的爆炸，可以播放
                    m_bombs[k].m_Free=false;
                    //更新爆炸坐标
                    m_bombs[k].m_x=m_hero.m_X;
                    m_bombs[k].m_y=m_hero.m_Y;
                    break;
                }

            }
            continue;

        }
        //遍历所有非空闲子弹
        for(int j=0;j<BULLET_NUM;j++)
        {
            //空闲子弹则执行下一次循环
            if(m_hero.m_bullets[j].m_free)
            {
                continue;
            }

            //如果子弹边框和敌机边框相交则说明发生碰撞，
            if(m2_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_rect))
            {
                m2_enemys[i].hp--;
                shoot_fireball(i);
                m_hero.m_bullets[j].m_free=true;
                if(m2_enemys[i].hp <= 0){
                    m2_enemys[i].m_Free=true;
                    score += 50;
                    //播放爆炸效果
                    for(int k=0;k<BOMB_NUM;k++)
                    {
                        if(m_bombs[k].m_Free)
                        {
                            //播放爆炸音效
                            QSound::play(SOUND_BOMB);
                            //空闲的爆炸，可以播放
                            m_bombs[k].m_Free=false;
                            //更新爆炸坐标
                            m_bombs[k].m_x=m2_enemys[i].m_x;
                            m_bombs[k].m_y=m2_enemys[i].m_y;
                            break;
                        }
                     }
                }


              }
          }
      }
    //boss子弹与hero碰撞
    for(int i=0;i<BOSS_BULLET_NUM;i++)
    {
        if(boss.linear_bullets[i].free) continue;
        if(boss.linear_bullets[i].rect.intersects(m_hero.m_rect))
        {
            if(!m_hero.flash_recorder){
                m_hero.hp--;
                 QSound::play(SOUND_HERT);
                m_hero.flash_recorder += HERO_FLASH_TIME;
            }
            boss.linear_bullets[i].free=true;
        }
    }
    for(int i=0;i<BOSS_TRACE_BULLET_NUM;i++)
    {
        if(boss.trace_bullets[i].free) continue;
        if(boss.trace_bullets[i].rect.intersects(m_hero.m_rect))
        {
            if(!m_hero.flash_recorder){
                m_hero.hp--;
                 QSound::play(SOUND_HERT);
                m_hero.flash_recorder += HERO_FLASH_TIME;
            }
            boss.trace_bullets[i].free=true;
        }
    }
    for(int i=0;i<BOSS_SPRINKLER_BULLET_NUM;i++)
    {
        if(boss.sprinkler_bullets[i].free) continue;
        if(boss.sprinkler_bullets[i].rect.intersects(m_hero.m_rect))
        {
            if(!m_hero.flash_recorder){
                m_hero.hp--;
                 QSound::play(SOUND_HERT);
                m_hero.flash_recorder += HERO_FLASH_TIME;
            }
            boss.sprinkler_bullets[i].free=true;
        }
    }
    //hero普通子弹与boss碰撞
    if(boss.m_come&&!boss.m_free)
    for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_hero.m_bullets[i].m_free) continue;
        if(m_hero.m_bullets[i].m_rect.intersects(boss.m_rect))
        {
            boss.hp-=1;
            m_hero.m_bullets[i].m_free=true;
        }
    }
    //hero超级子弹与boss碰撞
    if(boss.m_come&&!boss.m_free)
    for(int i=0;i<SUPER_BULLET_NUM;i++)
    {
        if(m_hero.super_bullets[i].m_free) continue;
        if(m_hero.super_bullets[i].m_rect.intersects(boss.m_rect))
        {
            boss.hp-=6;
            m_hero.super_bullets[i].m_free=true;
        }
    }
}

void MainScene::gameover()
{
    if(m_hero.hp){
        if(boss.defeated && boss.m_Y + boss.boss_mode.height() <= 0){
            boss_defeated();
        }
        return;
    }
    m_Timer.stop();
    player->stop();
    QSound::play(SOUND_GAMEOVER);
    QMessageBox::information(nullptr, "游戏结束", "您已阵亡");
    this->close();
}

void MainScene::enemyToScene()   //敌机出场；
{
    m_recorder++;
    //未到出场时间
    if(m_recorder<ENEMY_INTERVAL)
        return ;
    //达到出场时间，重置记录
    m_recorder=0;
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free=false;
            m_enemys[i].m_x=rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemys[i].m_y=-m_enemys[i].m_Rect.height();
            break;
        }

    }
}

//2号敌机出场；
void MainScene::enemy2ToScene()
{
    m2_recorder++;
    //未到出场时间
    if(m2_recorder<ENEMY2_INTERVAL)
        return ;
    //达到出场时间，重置记录
    m2_recorder=0;
    for(int i=0;i<ENEMY2_NUM;i++)
    {
        if(m2_enemys[i].m_Free)
        {

            m2_enemys[i].m_Free=false;
            m2_enemys[i].m_x=rand()%(GAME_WIDTH-m2_enemys[i].m_Rect.width());
            m2_enemys[i].m_y=-m2_enemys[i].m_Rect.height();
            m2_enemys[i].hp = 3;
            break;
        }

    }
}

//需要显示的东西都要经过这儿画出来
void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //画地图
    painter.drawPixmap(0,m_map.m_map1_posY , m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY , m_map.m_map2);
    //画玩家飞机
    if(m_hero.flag)
        painter.drawPixmap(m_hero.m_X, m_hero.m_Y, m_hero.m_plane);
    if(score <= SCORE_LEVEL){

        scoreboard->setText("Score: " + QString::number(score)); // 更新得分显示；
    }else{
        scoreboard->hide();
    }
    //画普通子弹
    for(int i = 0 ; i < BULLET_NUM; i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!m_hero.m_bullets[i].m_free)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_bullet);
        }
    }
    //画超级子弹
    bool flag = true;
    for(int i = 0 ; i < 30; i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!m_hero.super_bullets[i].m_free)
        {
            if(flag){
                flag = false;
                QSound::play(SOUND_SUPER_BULLET);
            }
            painter.drawPixmap(m_hero.super_bullets[i].m_X,m_hero.super_bullets[i].m_Y,m_hero.super_bullets[i].m_bullet);
        }
    }
    //画生命值，飞机hp为几就画几个爱心
    for(int i = 0; i < m_hero.hp; i++)
    {
        painter.drawPixmap(i*20,0,m_hero.heart_pic);
    }
    //画buff
    for(int i = 0; i < BUFF_NUM; i++)
    {
        if(!buffs[i].m_free)
        {
            painter.drawPixmap(buffs[i].m_X,buffs[i].m_Y,buffs[i].buff_pic);
        }
    }
    for(int i = 0; i < BUFF_NUM; i++)
    {
        if(!hpbuffs[i].m_free)
        {
            painter.drawPixmap(hpbuffs[i].m_X, hpbuffs[i].m_Y, hpbuffs[i].buff_pic);
        }
    }
    //画敌机
    for(int i = 0; i < ENEMY_NUM; i++){
        if(!m_enemys[i].m_Free){
            painter.drawPixmap(m_enemys[i].m_x, m_enemys[i].m_y, m_enemys[i].m_enemy);
        }
    }
    //画2号敌机
    for(int i = 0; i < ENEMY2_NUM; i++){
        if(!m2_enemys[i].m_Free){

            painter.drawPixmap(m2_enemys[i].m_x, m2_enemys[i].m_y, m2_enemys[i].m_enemy);
        }
    }
    //画火球
    for(int i = 0; i < FIREBALL_NUM; i++){
        if(!m_fireballs[i].m_Free){
            painter.drawPixmap(m_fireballs[i].m_x, m_fireballs[i].m_y, m_fireballs[i].ball);
        }
    }
    //画血包
    if(!m_hppotion.m_free && m_hppotion.flag){
        painter.drawPixmap(m_hppotion.m_x, m_hppotion.m_y, m_hppotion.m_heart);
    }
    //画boss
    if(!boss.m_free){
        painter.drawPixmap(boss.m_X,boss.m_Y,boss.boss_mode);
    }
    //画boss的子弹
    for(int i=0;i<BOSS_BULLET_NUM;i++){
        if(!boss.linear_bullets[i].free){
            painter.drawPixmap(boss.linear_bullets[i].X,boss.linear_bullets[i].Y,boss.linear_bullets[i].mode);
        }
    }
    for(int i=0;i<BOSS_TRACE_BULLET_NUM;i++){
        if(!boss.trace_bullets[i].free){
            painter.drawPixmap(boss.trace_bullets[i].X,boss.trace_bullets[i].Y,boss.trace_bullets[i].mode);
        }
    }
    for(int i=0;i<BOSS_SPRINKLER_BULLET_NUM;i++){
        if(!boss.sprinkler_bullets[i].free){
            painter.drawPixmap(boss.sprinkler_bullets[i].X,boss.sprinkler_bullets[i].Y,boss.sprinkler_bullets[i].mode);
        }
    }
    //画boss的血条
    if(!boss.m_free)
    {
        QBrush red_brush(QColor(Qt::red));
        painter.setBrush(red_brush);
        double rate = 1.0*boss.hp/BOSS_HP;
        painter.drawRect(boss.m_X,boss.m_Y-2,rate*boss.boss_mode.width(),0.1*rate*boss.boss_mode.height());
    }
    //绘制爆炸
    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free==false){
            painter.drawPixmap(m_bombs[i].m_x,m_bombs[i].m_y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
}

/************键盘操作, 不用管************************/
void MainScene::keyPressEvent(QKeyEvent *event)
{
    //如果不是长按时自动触发的press, 就将key值加入list
    if(!event->isAutoRepeat()) keys.append(event->key());
    //如果定时器不在运行, 就启动一下
    if(!keyRespondTimer->isActive()) keyRespondTimer->start(4);
}

void MainScene::keyReleaseEvent(QKeyEvent *event)
{
    //如果不是长按时自动触发的release, 就将key值从容器中删除
    if(!event->isAutoRepeat()) keys.removeAll(event->key());
    //如果容器空了，就关闭定时器
    if(keys.isEmpty()) keyRespondTimer->stop();
}

void MainScene::slotTimeOut()
{
    foreach(int key, keys)
    {
        switch(key)
        {
            case Qt::Key_W:
                if(m_hero.m_Y <= 0) break;
                m_hero.m_Y-=1;
                m_hero.setPosition(m_hero.m_X,m_hero.m_Y);
            break;
            case Qt::Key_S:
                if(m_hero.m_Y+m_hero.m_plane.height() >= GAME_HEIGHT) break;
                m_hero.m_Y+=1;
                m_hero.setPosition(m_hero.m_X,m_hero.m_Y);
            break;
            case Qt::Key_A:
                if(m_hero.m_X <= 0) break;
                m_hero.m_X-=1;
                m_hero.setPosition(m_hero.m_X,m_hero.m_Y);
            break;
            case Qt::Key_D:
                if(m_hero.m_X+m_hero.m_plane.width() >= GAME_WIDTH) break;
                m_hero.m_X+=1;
                m_hero.setPosition(m_hero.m_X,m_hero.m_Y);
            break;
            default: break;
        }
    }
}
/************键盘操作, 不用管************************/
