#include "pea.h"
#include "config.h"
#include <QGraphicsScene>
#include "basic_zombie.h"
#include <QDebug>

Pea::Pea()
{
    pixmap = new QPixmap(RESOURCE_PATH + "/images/plants/Pea.png");
}

Pea::~Pea()
{
    delete pixmap;
    qDebug() << "Pea destroyed\n";
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
