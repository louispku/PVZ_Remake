#ifndef FUMESHROOM_H
#define FUMESHROOM_H

#include "mushroom.h"

class FumeShroom : public Mushroom
{
public:
    static constexpr int init_hp = 300;
    static constexpr int atk = 20;
    static constexpr int attack_interval = 1400; // 攻击间隔(ms)
    static constexpr int attack_distance = 330; // pixels
public:
    FumeShroom(BattleWindow::MapType mapType);
    ~FumeShroom();
    QRectF boundingRect() const override;
    // bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void wakeup() override;

private:
    int attack_counter;
    int anime_counter;
    QPixmap *bullets[8];
    int state; // 1-for attacking
};

#endif // FUMESHROOM_H
