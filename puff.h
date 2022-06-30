#ifndef PUFF_H
#define PUFF_H

#include <QGraphicsItem>

class Puff : public QGraphicsItem
{
private:
    QPixmap* pixmap;
    static constexpr qreal move_speed = 360.0; // pixels per sec
    qreal stopX;

public:
    static constexpr int atk = 20;
public:
    Puff(qreal stpx);
    ~Puff();
    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;
    void advance(int phase) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // PUFF_H
