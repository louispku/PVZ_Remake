#ifndef WALLNUT_H
#define WALLNUT_H

#include "basic_plant.h"

class WallNut : public Basic_Plant
{
public:
    static constexpr int init_hp = 4000;
    static constexpr int cracked1 = 2666;
    static constexpr int cracked2 = 1333;

public:
    WallNut();
    // bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;

private:
    int stage;
};

#endif // WALLNUT_H
