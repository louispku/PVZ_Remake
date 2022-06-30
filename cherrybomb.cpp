#include "cherrybomb.h"
#include "basic_zombie.h"
#include "config.h"
#include <QMovie>

CherryBomb::CherryBomb() : stage(0)
{
    hp = init_hp;
    setMovie(RESOURCE_PATH + "/images/plants/CherryBomb/CherryBomb.gif");
}

bool CherryBomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    auto vec = other->pos() - pos();
    return other->type() == Basic_Zombie::Type && QPointF::dotProduct(vec, vec) < 24000.0;
}

void CherryBomb::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }
    update();

    if (stage == 0 &&
        movie->currentFrameNumber() == movie->frameCount() - 1)
    {
        auto cldlist = collidingItems();
        for (auto item : qAsConst(cldlist))
        {
            qgraphicsitem_cast<Basic_Zombie*>(item)->attacked(1800, Bomb);
        }
        setMovie(RESOURCE_PATH + "/images/plants/CherryBomb/Boom.gif");
        stage = 1;

    }
    else if (stage == 1 &&
             movie->currentFrameNumber() == movie->frameCount() - 1)
    {
        deleteSelf();
        return;
    }

}
