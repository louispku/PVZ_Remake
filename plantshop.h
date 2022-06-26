#ifndef PLANTSHOP_H
#define PLANTSHOP_H

#include "basic_plant.h"
#include "basic_widget.h"
#include "plantcard.h"
#include "sun.h"
#include "sunflower.h"
#include "peashooter.h"
#include "cherrybomb.h"
#include "wallnut.h"
#include "snowpea.h"
#include "potatomine.h"
#include "repeater.h"
#include "basiczombie.h"

class PlantShop : public Basic_Widget
{
public:
    int sun;
    PlantShop();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void addPlant(QString s, QPointF pos);
    int counter;
    int time;
};

#endif // PLANTSHOP_H

