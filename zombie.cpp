#include "zombie.h"
#include "config.h"
#include <QMovie>
#include <QPainter>
#include "basic_plant.h"


Zombie::Zombie()
{
    hp = 170;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;

    setMovie(RESOURCE_PATH + "/images/zombies/Zombie/Zombie.gif");
}

void Zombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state == 4)
        {
            delete this;
        }
        else if (state == 3)
        {
            state = 2;
            setMovie(RESOURCE_PATH + "/images/zombies/BoomDie.gif");
        }
        else if (state < 2)
        {
            state = 2;
            setMovie(RESOURCE_PATH + "/images/zombies/Zombie/ZombieDie.gif");
            setHead(RESOURCE_PATH + "/images/zombies/Zombie/ZombieHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
        {
            scene()->removeItem(this);
            delete this;
        }

        return;
    }

    QList<QGraphicsItem *> itemlist = collidingItems();
    if (!itemlist.isEmpty())
    {
        Basic_Plant *plant = qgraphicsitem_cast<Basic_Plant *>( itemlist[0] );
        plant->hp -= atk;
        if (state != 1)
        {
            state = 1;
            setMovie(RESOURCE_PATH + "/images/zombies/Zombie/ZombieAttack.gif");
        }
        return;
    }


    if (state)
    {
        state = 0;

        setMovie(RESOURCE_PATH + "/images/zombies/Zombie/Zombie.gif");

    }
    setX(x() - speed);


}
