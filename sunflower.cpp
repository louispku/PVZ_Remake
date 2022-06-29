#include "sunflower.h"
#include "config.h"
#include "qgraphicsscene.h"
#include "sun.h"
#include <QMovie>

SunFlower::SunFlower() : counter(0)
{
    setMovie(RESOURCE_PATH + "/images/plants/SunFlower/SunFlower.gif");
}

void SunFlower::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }

    update();

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

