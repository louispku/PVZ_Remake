#ifndef SUNSHROOM_H
#define SUNSHROOM_H

#include "mushroom.h"

class SunShroom : public Mushroom
{
public:
    static constexpr int init_hp = 300;
    static constexpr int sun_interval = 20000; // 生产阳光间隔(ms)

private:
    int counter;

public:
    SunShroom(BattleWindow::MapType mapType);
    // bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;
    void wakeup() override;
};

#endif // SUNSHROOM_H
