#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "basic_plant.h"
#include <QPainter>

class Peashooter : public Basic_Plant
{
public:
    static constexpr int init_hp = 300;
    static constexpr int attack_interval = 1400; // 攻击间隔(ms)
public:
    Peashooter();
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;

private:
    int attack_counter;
};

#endif // PEASHOOTER_H
