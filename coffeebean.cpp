#include "coffeebean.h"

int CoffeeBean::type() const
{
    return Type;
}

CoffeeBean::CoffeeBean(Mushroom *sleepMushroom) : Basic_Plant(sleepMushroom)
{
    counter = 0;
    state = 0;
    to_wake = sleepMushroom;
    hp = 10000;
    setMovie(RESOURCE_PATH + "/images/plants/CoffeeBean/CoffeeBeanEat.gif");
}

void CoffeeBean::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }

    update();

    if (movie->currentFrameNumber() == movie->frameCount() - 1)
    {
        to_wake->wakeup();
        scene()->removeItem(this);
        delete this;
        return;
    }
}

QRectF CoffeeBean::boundingRect() const
{
    return QRectF(-19, -62, 39, 97);
}
