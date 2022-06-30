#include "puff.h"
#include "config.h"
#include "qgraphicsscene.h"
#include "basic_zombie.h"
#include "basic_plant.h"

Puff::Puff(qreal stpx) : stopX(stpx)
{
    pixmap = new QPixmap(RESOURCE_PATH + "/images/plants/PuffShroom_puff.png");
}

Puff::~Puff()
{
    delete pixmap;
}

QRectF Puff::boundingRect() const
{
    return QRectF(-10.0, -10.0, 20.0, 20.0);
}

bool Puff::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 10
            && other->type() == Basic_Zombie::Type;
}

void Puff::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }

    if (x() > stopX) // 超出射程
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

void Puff::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(boundingRect(), pixmap->toImage());
}

