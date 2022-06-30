#include "peashooter.h"
#include "basic_zombie.h"
#include "pea.h"
#include <QGraphicsScene>
#include "config.h"

Peashooter::Peashooter()
{
    attack_counter = 0;
    hp = init_hp;
    setMovie(RESOURCE_PATH + "/images/plants/Peashooter/Peashooter.gif");
}

bool Peashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return qFuzzyCompare(y(), other->y())
           &&
           other->type() == Basic_Zombie::Type;
}

void Peashooter::advance(int phase)
{
    static const int count_max = FPS * attack_interval / 1000;
    if (phase == 0)
    {
        return;
    }

    update();

    if (hp <= 0)
    {
        // TODO: play death sound

        deleteSelf();
        return;
    }

    if (attack_counter >= count_max)
    {
        auto cldlist = scene()->items(x(), y(), 1400.0, 10.0, Qt::IntersectsItemBoundingRect, Qt::AscendingOrder);
        for (auto item : cldlist)
        {
            if (item->type() == Basic_Zombie::Type && qFuzzyCompare(y(), item->y()))
            {
                attack_counter = 0;
                auto pea = new Pea;
                pea->setX(x() + 28);
                pea->setY(y());
                scene()->addItem(pea);
                break;
            }
        }
    }
    else
    {
        attack_counter++;
    }

}
