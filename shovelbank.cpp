#include "shovelbank.h"
#include "battlewindow.h"
#include "config.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

ShovelBank::ShovelBank() : selected(false)
{
    background = new QPixmap(RESOURCE_PATH + "/images/interface/ShovelBank.png");
    shovelImage = new QPixmap(RESOURCE_PATH + "/images/interface/Shovel.png");
}

ShovelBank::~ShovelBank()
{
    delete background;
    delete shovelImage;
}

QRectF ShovelBank::boundingRect() const
{
    return QRectF(0.0, 0.0, 88.0, 90.0);
}

void ShovelBank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawPixmap(QRect(0.0, 0.0, 88, 90), *background);

    if (!selected)
    {
        painter->drawPixmap(0, 0, *shovelImage);
    }

}

void ShovelBank::advance(int stage)
{
    if (stage == 0)
    {
        return;
    }

    update();
}

void ShovelBank::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
    {
        return;
    }

    if (!selected)
    {
        selected = true;
        reinterpret_cast<BattleWindow*>(scene()->parent())->seedbank->selected = false;
        emit shovelSelected(-2);
        reinterpret_cast<BattleWindow*>(scene()->parent())->setCursor(QCursor(*shovelImage));
    }
    else
    {
        selected = false;
        emit shovelSelected(-1);
        reinterpret_cast<BattleWindow*>(scene()->parent())->setCursor(Qt::ArrowCursor);
    }
}

