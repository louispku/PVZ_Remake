#ifndef CONFIG_H
#define CONFIG_H
#include <QString>

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
    150
};

// in sec
const int CoolDown[] =
{
    10,
    10,
    20
};

#endif // CONFIG_H
