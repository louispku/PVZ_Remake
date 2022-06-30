#include "pea.h"
#include "config.h"
#include <QGraphicsScene>
#include "basic_zombie.h"
#include "basic_plant.h"
#include <QDebug>

Pea::Pea()
{
    pixmap = new QPixmap(RESOURCE_PATH + "/images/plants/Pea.png");
}

Pea::~Pea()
{
    delete pixmap;
}

QRectF Pea::boundingRect() const
{
    return QRectF(-12, -28, 24, 24);
}

bool Pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 10
           && other->type() == Basic_Zombie::Type;
}

void Pea::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }

    if (x() > 900.0) // 超出屏幕
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    else
    {
        setX(x() + move_speed / FPS);
    }

    auto cldlist = collidingItems();
    if (!cldlist.empty())
    {
        QGraphicsItem* leftmostItem = cldlist.front();
        qgraphicsitem_cast<Basic_Zombie*>(leftmostItem)->attacked(atk, Basic_Plant::Normal);

        scene()->removeItem(this);
        delete this;
        return;
    }

}

void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(boundingRect(), pixmap->toImage());
}
