#ifndef REPEATER_H
#define REPEATER_H

#include "basic_plant.h"

class Repeater : public Basic_Plant
{
public:
    static constexpr int init_hp = 300;
    static constexpr int attack_interval = 1400; // 攻击间隔(ms)
public:
    Repeater();
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;

private:
    int attack_counter;
    int state; // 0-wait, 1-shot one pea
};

#endif // REPEATER_H
