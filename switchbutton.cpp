#include "switchbutton.h"
#include "plantselectwindow.h"
#include <QPainter>

SwitchButton::SwitchButton(const QString &str) : text(str), state(0)
{
}

QRectF SwitchButton::boundingRect() const
{
    return QRectF(-70, -35 ,160, 70);
}

void SwitchButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(QRectF(-70, -35 ,160, 70), pixmap->toImage());
}

void SwitchButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    state = 1;
}

void SwitchButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (state == 1)
    {
        emit gameplay(Selection_Button::plant_list);
    }
    state = 0;
}


