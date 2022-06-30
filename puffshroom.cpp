#include "puffshroom.h"
#include "config.h"
#include "basic_zombie.h"
#include "puff.h"

PuffShroom::PuffShroom(BattleWindow::MapType mapType) : Mushroom(mapType)
{
    hp = init_hp;
    attack_counter = 0;
    if (awake)
    {
        setMovie(RESOURCE_PATH + "/images/plants/PuffShroom/PuffShroom.gif");
    }
    else
    {
        setMovie(RESOURCE_PATH + "/images/plants/PuffShroom/PuffShroomSleep.gif");
    }
}

QRectF PuffShroom::boundingRect() const
{
    return QRectF(-20.0, -33.0, 40.0, 66.0);
}

bool PuffShroom::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    qreal diff = other->x() - x();
    return other->type() == Basic_Zombie::Type
           && qFuzzyCompare(y(), other->y())
           && diff < attack_distance
            && diff > -20.0;
}

void PuffShroom::advance(int phase)
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

    if (awake && attack_counter >= count_max)
    {
        auto cldlist = scene()->items(x(), y(), attack_distance, 10.0, Qt::IntersectsItemBoundingRect, Qt::AscendingOrder);
        for (auto item : cldlist)
        {
            if (item->type() == Basic_Zombie::Type && qFuzzyCompare(y(), item->y()))
            {
                attack_counter = 0;
                auto puff = new Puff(x() + attack_distance);
                puff->setX(x() + 15.0);
                puff->setY(y());
                scene()->addItem(puff);
                break;
            }
        }
    }
    else
    {
        attack_counter++;
    }
}

void PuffShroom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(QRectF(-20.0, -50.0, 40.0, 66.0), movie->currentImage());
}

void PuffShroom::wakeup()
{
    awake = true;
    setMovie(RESOURCE_PATH + "/images/plants/PuffShroom/PuffShroom.gif");
}
