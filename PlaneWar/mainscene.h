#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QIcon>
#include <QList>
#include <ctime>
#include <cstdlib>
#include <QResource>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QFont>
#include <QMediaPlayer>
#include <QString>
#include <QSound>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMovie>
#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include "buff.h"
#include "enemyplane.h"
#include "boss.h"
#include "bomb.h"
#include "gameover.h"
#include "hppotion.h"
#include "enemy2.h"



class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();



    void initScene(); // 场景初始化
    void playGame(); //游戏启动
    void updatePosition(); //更新位置
    void buffToScene(); //buff出现在场景中
    void hpbuffToScene(); //回血buff出现
    void bossToScene(); //boss出场
    void collisionDetect(); //碰撞检测
    void gameover(); // 游戏结束；
    void enemyToScene(); //敌机出场；

    void boss_defeated();


    void paintEvent(QPaintEvent *event) override; //绘图
    void keyPressEvent(QKeyEvent *event) override; //用键盘操作飞机移动
    void keyReleaseEvent(QKeyEvent *event) override; //松开按键


public:


    int score; //记录得分；
    QLabel *scoreboard;   //记分板；
    Map m_map; //地图
    HeroPlane m_hero; //玩家飞机
    int buff_recorder; //记录buff出场
    int hpbuff_recorder; //记录回血buff的出场
    Buff buffs[BUFF_NUM]; //buff
    Buff hpbuffs[BUFF_NUM]; //加血的buff
    int boss_recorder; //记录boss出场
    Boss boss; //boss
    int m_recorder; //记录敌机出场;
    enemyPlane m_enemys[ENEMY_NUM]; //敌机
    enemy2 m2_enemys[ENEMY2_NUM];  //敌机2号
    int m2_recorder;                //记录出场
    void enemy2ToScene();          //敌机2号出场
    fireball m_fireballs[FIREBALL_NUM];  //敌机发出的火球
    void shoot_fireball(int i);           //敌机发射火球
    void hppotionToScene();              //血包出场
    hp_potion m_hppotion;           //血包
    int potion_recorder;             //血包出场记录

    bomb m_bombs[BOMB_NUM];              //爆炸

    QMediaPlayer *player = new QMediaPlayer;


private:
    QTimer m_Timer; //定时器，负责屏幕刷新间隔
/******************这是键盘移动用的，可以不用管********************/
    QTimer *keyRespondTimer; //负责键盘操作的定时器
    QList<int> keys;
    void slotTimeOut();
/******************这是键盘移动用的，可以不用管********************/
private slots:


    //void on_start_button_clicked();

};

#endif // MAINSCENE_H
