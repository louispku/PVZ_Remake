#ifndef PEA_H
#define PEA_H

#include "basic_widget.h"
#include <QPixmap>
#include <QPainter>

class Pea : public Basic_Widget
{
private:
    QPixmap* pixmap;
    static constexpr qreal move_speed = 360.0; // pixels per sec

public:
    static constexpr int atk = 20;
public:
    Pea();
    ~Pea();
    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // PEA_H
