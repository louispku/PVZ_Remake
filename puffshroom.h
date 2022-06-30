#ifndef PUFFSHROOM_H
#define PUFFSHROOM_H

#include "mushroom.h"


class PuffShroom : public Mushroom
{
public:
    static constexpr int init_hp = 300;
    static constexpr int attack_interval = 1400; // 攻击间隔(ms)
    static constexpr int attack_distance = 250; // pixels
public:
    PuffShroom(BattleWindow::MapType mapType);
    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void wakeup() override;

private:
    int attack_counter;
};

#endif // PUFFSHROOM_H
