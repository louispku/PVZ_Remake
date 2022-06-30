#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "basic_plant.h"

class SunFlower : public Basic_Plant
{
public:
    static constexpr int init_hp = 300;
    static constexpr int sun_interval = 20000; // 生产阳光间隔(ms)

private:
    int counter;

public:
    SunFlower();
    // bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;
};

#endif // SUNFLOWER_H
