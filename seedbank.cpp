#include "seedbank.h"
#include <QPainter>
#include "basic_plant.h"
#include "config.h"
#include "seedpacket.h"

SeedBank::SeedBank(const QVector<int>& plants) : sun(1000), selected(false)
{
    pixmap = new QPixmap(RESOURCE_PATH + "/images/interface/SeedBank.png");
    for (int i = 0; i < plants.size(); i++)
    {
        SeedPacket* seedpacket = new SeedPacket(plants[i], this);
        seedpacket->setPos(-157 + 65 * i, -2);
    }
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



