#ifndef CONFIG_H
#define CONFIG_H
#include <QString>

#define SHORT_CD 7
#define MIDDLE_CD 20
#define LONG_CD 40

static constexpr int FPS = 30; // 画面帧率, 所有部件的操作以帧为单位进行
static const QString RESOURCE_PATH = "../PVZ_Remake/resources";

enum
{
    PEASHOOTER = 0,
    SUNFLOWER = 1,
    CHERRYBOMB = 2,
    WALLNUT = 3,
    POTATOMINE = 4,
    SNOWPEA = 5,
    REPEATER = 6,
    PUFFSHROOM = 7, // 小喷菇
    SUNSHROOM = 8,
    FUMESHROOM = 9, // 大喷菇
    COFFEEBEAN = 10
};


// 必须与资源目录的文件夹名称相同
const QString PlantName[] =
{
    "Peashooter",
    "SunFlower",
    "CherryBomb",
    "WallNut",
    "PotatoMine",
    "SnowPea",
    "Repeater",
    "PuffShroom",
    "SunShroom",
    "FumeShroom",
    "CoffeeBean"
};


const int Cost[] =
{
    100,
    50,
    150,
    50,
    25,
    175,
    200,
    0,
    25,
    75,
    75
};

// in sec
const int CoolDown[] =
{
    SHORT_CD,
    SHORT_CD,
    LONG_CD,
    MIDDLE_CD,
    MIDDLE_CD,
    SHORT_CD,
    SHORT_CD,
    SHORT_CD,
    SHORT_CD,
    SHORT_CD,
    SHORT_CD
};

#endif // CONFIG_H
