#include "seedbank.h"
#include <QPainter>
#include "config.h"

SeedBank::SeedBank() : sun(50)
{
    pixmap = new QPixmap(RESOURCE_PATH + "/images/interface/SeedBank.png");
}

QRectF SeedBank::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void SeedBank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-270, -45, 540, 90), *pixmap);
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
    painter->drawPoint(-220, 0);
}

void SeedBank::advance(int stage)
{
    if (stage == 0)
    {
        return;
    }
    update();
}



