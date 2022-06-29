#include "text.h"
#include <QString>
#include <QRectF>
Text::Text(QString tmp):texttoPaint(tmp)
{

}

QRectF Text::boundingRect()const{

    return QRectF(-150.0,-75.0,300.0,150.0);
}


void Text::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget)
    Q_UNUSED(option)
    painter->setPen(Qt::white);
    QFont font;
    font.setPointSize(15);
    painter->setFont(font);
    painter->drawText(boundingRect(),texttoPaint);

}
