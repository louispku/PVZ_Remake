#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "basic_plant.h"

class Peashooter : public Basic_Plant
{
public:
    static constexpr int init_hp = 100;
public:
    Peashooter();
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // PEASHOOTER_H
