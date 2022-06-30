#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include "basic_plant.h"

class CherryBomb : public Basic_Plant
{
public:
    static constexpr int init_hp = 100000;

public:
    CherryBomb();
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;

private:
    int stage; // 0 before explosion, 1 after explosion

};


#endif // CHERRYBOMB_H
