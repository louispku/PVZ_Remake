#include "potatomine.h"
#include "config.h"
#include "basic_zombie.h"
#include <QMovie>

PotatoMine::PotatoMine()
{
    counter = 0;
    state = 0;
    hp = init_hp;
    radius = 30.0;
    setMovie(RESOURCE_PATH + "/images/plants/PotatoMine/PotatoMine1.gif");
}

bool PotatoMine::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Basic_Zombie::Type &&
            qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < radius;
}

void PotatoMine::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }
    update();

    if (state == 0)
    {
        if (counter < readyTime * FPS)
        {
            counter++;
            if (hp <= 0)
            {
                deleteSelf();
                return;
            }
        }
        else
        {
            state = 1;
            setMovie(RESOURCE_PATH + "/images/plants/PotatoMine/PotatoMine.gif");
            radius = 40.0;
        }
    }
    else if (state == 1)
    {
        auto cldlist = collidingItems();
        if (!cldlist.empty())
        {
            state = 2;
            setMovie(RESOURCE_PATH + "/images/plants/PotatoMine/PotatoMineBomb.gif");
            for (auto item : qAsConst(cldlist))
            {
                qgraphicsitem_cast<Basic_Zombie*>(item)->attacked(1800, Mine);
            }
        }
    }
    else if (state == 2)
    {
        if (movie->currentFrameNumber() == movie->frameCount() - 1)
        {
            deleteSelf();
            return;
        }
    }
}
