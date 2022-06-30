#include "wallnut.h"
#include "config.h"

WallNut::WallNut() : stage(0)
{
    hp = init_hp;
    setMovie(RESOURCE_PATH + "/images/plants/WallNut/WallNut.gif");
}

void WallNut::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }

    update();

    if (hp <= 0)
    {
        deleteSelf();
        return;
    }
    else if (stage < 2 && hp <= cracked2)
    {
        stage = 2;
        setMovie(RESOURCE_PATH + "/images/plants/WallNut/Wallnut_cracked2.gif");
    }
    else if (stage == 0 && hp <= cracked1)
    {
        stage = 1;
        setMovie(RESOURCE_PATH + "/images/plants/WallNut/Wallnut_cracked1.gif");
    }

}
