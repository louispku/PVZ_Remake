#include "sunshroom.h"
#include "config.h"


SunShroom::SunShroom(BattleWindow::MapType mapType) : Mushroom(mapType)
{
    hp = init_hp;
    counter = 0;
    if (awake)
    {
        setMovie(RESOURCE_PATH + "/images/plants/SunShroom/SunShroom.gif");
    }
    else
    {
        setMovie(RESOURCE_PATH + "/images/plants/SunShroom/SunShroomSleep.gif");
    }
}

void SunShroom::advance(int phase)
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

    if (awake)
    {
        if (counter >= FPS * sun_interval / 1000)
        {
            auto sun = new Sun(y() + 60.0);
            sun->setPos(x() + 10.0, y() - 15.0);
            scene()->addItem(sun);
            counter = 0;
        }
        else
        {
            counter++;
        }
    }

}

void SunShroom::wakeup()
{
    awake = true;
    setMovie(RESOURCE_PATH + "/images/plants/SunShroom/SunShroom.gif");
}
