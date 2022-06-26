#include "peashooter.h"
#include "basic_zombie.h"
#include "pea.h"
#include <QGraphicsScene>
#include "config.h"

Peashooter::Peashooter()
{
    hp = init_hp;
    setMovie("../PVZ_Remake/resources/images/plants/Peashooter/Peashooter.gif");
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
    static int attack_counter = count_max;
    if (phase == 0)
    {
        return;
    }

    if (hp <= 0)
    {
        // TODO: play death sound

        scene()->removeItem(this);
        delete this;
        return;
    }

    if (attack_counter >= count_max)
    {
        if (!collidingItems().empty())
        {
            attack_counter = 0;
            auto pea = new Pea;
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
        }
    }
    else
    {
        attack_counter++;
    }

}
