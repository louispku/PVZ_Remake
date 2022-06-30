#include "repeater.h"
#include "config.h"
#include "basic_zombie.h"
#include "pea.h"

Repeater::Repeater()
{
    hp = init_hp;
    attack_counter = 0;
    state = 0;
    setMovie(RESOURCE_PATH + "/images/plants/Repeater/Repeater.gif");
}

bool Repeater::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return qFuzzyCompare(y(), other->y())
           &&
            other->type() == Basic_Zombie::Type;
}

void Repeater::advance(int phase)
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

    if (state == 0)
    {
        if (attack_counter >= count_max)
        {
            auto cldlist = scene()->items(x(), y(), 1400.0, 10.0, Qt::IntersectsItemBoundingRect, Qt::AscendingOrder);
            for (auto item : qAsConst(cldlist))
            {
                if (item->type() == Basic_Zombie::Type && qFuzzyCompare(y(), item->y()))
                {
                    state = 1;
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
    else
    {
        if (attack_counter >= FPS / 4)
        {
            state = 0;
            attack_counter = 0;
            auto pea = new Pea;
            pea->setX(x() + 28);
            pea->setY(y());
            scene()->addItem(pea);
        }
        else
        {
            attack_counter++;
        }
    }
}



