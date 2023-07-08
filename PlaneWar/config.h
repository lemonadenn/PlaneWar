#ifndef CONFIG_H
#define CONFIG_H


//游戏配置信息
#define GAME_HEIGHT 930
#define GAME_WIDTH 620
#define GAME_RES_PATHONE "D:/PlaneWar/backgroundone.rcc"  //rcc文件路径
#define GAME_RES_PATHTWO "D:/PlaneWar/gamestart.rcc"
#define GAME_RES_PATHTHREE "D:/stor/story.rcc"

#define GAME_TITLE "Thunder"
#define GAME_SRC_PATH "D:/PlaneWar/src.rcc" //rcc文件路径
#define GAME_ICON "D:/PlaneWar/src/app.ico"
#define GAME_RATE 10 //屏幕刷新间隔

#define MP4_PATH "D:/PlaneWar/src/dddd.mp4"
#define GIF_PATH "D:/PlaneWar/src/bigbang.gif"

#define SCORE_LEVEL 1000
//************************************************************
//音效配置
#define SOUND_BACKGROUND2 "D:/PlaneWar/src/bg.wav"
#define SOUND_BACKGROUND1 "D:/PlaneWar/src/background.wav"
#define SOUND_BOMB "D:/PlaneWar/src/bomb.wav"
#define SOUND_GAMEOVER "D:/PlaneWar/src/game_over.wav"
#define SOUND_BLOOD "D:/PlaneWar/src/blood.wav"
#define SOUND_UPDATE "D:/PlaneWar/src/update.wav"
#define SOUND_HERT "D:/PlaneWar/src/enemy2_down.wav"
#define SOUND_SUPER_BULLET "D:/PlaneWar/src/bullet.mp3"
//************************************************************
//地图配置
#define MAP_PATH "D:/PlaneWar/src/img_bg_level_2.jpg"
#define MAP_SCROLL_SPEED 2 //地图滚动速度
//************************************************************
//HeroPlane配置
#define HERO_PATH "D:/PlaneWar/src/hero.png"
#define HEART_PATH "D:/PlaneWar/src/heart.png"
#define HERO_HP 10
#define HERO_FLASH_TIME 80
#define HERO_FLASH_INTERVAL 10
//************************************************************
//Bullet配置
#define BULLET_PATH "D:/PlaneWar/src/bullet_11.png" //子弹图片路径
#define BULLET_SPEED 5  //子弹移动速度
#define BULLET_NUM 100   //弹匣中子弹总数
#define BULLET_INTERVAL 20 //发射子弹时间间隔
#define SUPER_BULLET_PATH "D:/PlaneWar/src/superbullet.png"
#define SUPER_BULLET_NUM 20 //超级子弹数量
//************************************************************
//Buff配置
#define BUFF_PATH "D:/PlaneWar/src/buff.png"
#define BUFF_SPEED 5
#define BUFF_INTERVAL 700 //buff出现时间,100就是1秒
#define BUFF_NUM 10
#define BUFF_REMAIN_TIME 1000 //buff持续时间
#define HP_BUFF_INTERVAL 800 //回血的buff出现间隔
//************************************************************
//敌机资源配置
#define ENEMY_PATH "D:/PlaneWar/src/img-plane_7.png"//敌机资源路径
#define ENEMY_SPEED 5 //敌机移动速度
#define ENEMY_NUM 30 //敌机数量
#define ENEMY_INTERVAL 30 //敌机出现间隔
#define ENEMY2_PATH "D:/PlaneWar/src/img-plane_3.png"
#define ENEMY2_SPEED 3
#define ENEMY2_NUM 30
#define ENEMY2_INTERVAL 60
#define FIREBALL_PATH "D:/PlaneWar/src/h_bullet_20.png"
#define FIREBALL_NUM 100
#define FIREBALL_SPEED 0.01
#define BALL_SIZE 40 //火球大小
//************************************************************
//血包资源配置
#define HPPOTION_PATH "D:/PlaneWar/src/heart.png"
#define HPPOTION_REMAIN_TIME 1000
#define FLASH_INTERVAL 20
#define HPPOTION_INTERVAL 1000
//************************************************************
//爆炸资源配置
#define BOMB_DIR "D:/PlaneWar/src/bomb_dir"
#define BOMB_NUM 32 //爆炸数量
#define BOMB_INTERVAL 10 //爆炸图片显示间隔
//************************************************************
//Boss配置
#define BOSS_PATH "D:/PlaneWar/src/boss2.png"
#define BOSS_SPEED 0.5 //boss移速
#define BOSS_HP 500 //boss血量
#define BOSS_INTERVAL 350 //boss在游戏开始后**s出现
#define MOVE_INTERVAL 300 //每3s移动一次
#define BOSS_BULLET_INTERVAL 60 //random shoot interval
#define BOSS_TRACE_INTERVAL 160 //trace shoot interval
#define BOSS_SPRINKLER_INTERVAL 30 //sprinkler shoot interval
#define BOSS_BULLET_NUM 30 //各种子弹的数量
#define BOSS_TRACE_BULLET_NUM 10
#define BOSS_SPRINKLER_BULLET_NUM 150
#define BOSS_RANDOM_SHOOT_TIME 600 //各种射击弹幕的持续时间
#define BOSS_TRACE_SHOOT_TIME 600
#define BOSS_SPRINKLER_SHOOT_TIME 1000
//************************************************************
//Boss子弹配置
#define BOSS_BULLET_PATH "D:/PlaneWar/src/bossbullet3.png"
#define BOSS_TRACE_BULLET_PATH "D:/PlaneWar/src/bossbullet2.png"
#define BOSS_SPRINKLER_BULLET_PATH "D:/PlaneWar/src/bossbullet1.png"
#define TRACE_EXIST_TIME 700 //追踪弹存在时间
#define BOSS_BULLET_SPEED 1
#define BOSS_TRACE_SPEED 1
#define BOSS_SPRINKLER_SPEED 2
//************************************************************
//数学常量
#define PI (4*atan(1))
#define EULER 2.71828
//************************************************************

#endif // CONFIG_H
