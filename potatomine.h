#ifndef POTATOMINE_H
#define POTATOMINE_H

#include "basic_plant.h"

class PotatoMine : public Basic_Plant
{
public:
    static constexpr int init_hp = 300;
    static constexpr int readyTime = 5; // in sec
    static constexpr int boomAnimeTime = 1; // in sec

public:
    PotatoMine();
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;

private:
    int state; // 0 not ready, 1 ready, 2 exploded
    int counter;
    qreal radius;
};

#endif // POTATOMINE_H
