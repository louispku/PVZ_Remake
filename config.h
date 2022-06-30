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

const QString plantName[] =
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

#endif // CONFIG_H
