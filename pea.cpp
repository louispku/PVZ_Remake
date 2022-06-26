#include "pea.h"

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
    return false;
}

void Pea::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }

    // TODO: check zombies and attack them (if any)
}

void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(boundingRect(), pixmap->toImage());
}
