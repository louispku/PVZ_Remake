#include "plant_card.h"
#include <QMovie>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPainter>

Plant_Card::Plant_Card(QPixmap *pixmap){
    pix = *pixmap;

}

Plant_Card::~Plant_Card(){

}




QRectF Plant_Card::boundingRect()const{
    return QRectF(-2-pix.width()/2,-2-pix.height()/2,pix.width()+4,pix.height()+4);
}

void Plant_Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(-pix.width()/2,-pix.height()/2,pix);

}
