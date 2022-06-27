#include "zombie.h"
#include "config.h"
#include <QMovie>
#include <QPainter>

Zombie::Zombie()
{
    hp = 270;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    if (qrand() % 2)
        setMovie(RESOURCE_PATH + "/images/zombies/Zombie/Zombie.gif");
    else
        setMovie(RESOURCE_PATH + "/images/zombies/Zombie/Zombie.gif");
}

void Zombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(RESOURCE_PATH + "/images/zombies/Zombie/ZombieDie.gif");
            setHead(RESOURCE_PATH + "/images/zombies/Zombie/ZombieHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }

    if (state)
    {
        state = 0;
        if (qrand() % 2)
            setMovie(RESOURCE_PATH + "/images/zombies/Zombie/Zombie.gif");
        else
            setMovie(RESOURCE_PATH + "/images/zombies/Zombie/Zombie.gif");
    }
    setX(x() - speed);
}
