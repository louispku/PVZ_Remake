#include "pea.h"
#include "config.h"
#include <QGraphicsScene>
#include "basic_zombie.h"

Pea::Pea()
{
    pixmap = new QPixmap("../PVZ_Remake/resources/images/plants/PB00.gif");
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
    Q_UNUSED(mode);
    return qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15
           && other->type() == Basic_Zombie::Type;
}

void Pea::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }

    if (x() > 600.0) // 超出屏幕
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
        QGraphicsItem* leftmostItem = nullptr;
        for (auto i : qAsConst(cldlist))
        {
            if (leftmostItem == nullptr || leftmostItem->x() > i->x())
            {
                leftmostItem = i;
            }
        }
        // TODO: attack i

        scene()->removeItem(this);
        delete this;
        return;
    }

}

void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(boundingRect(), pixmap->toImage());
}
