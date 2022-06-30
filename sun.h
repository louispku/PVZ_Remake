#ifndef SUN_H
#define SUN_H

#include <QGraphicsItem>
#include <QMovie>

class Sun : public QGraphicsItem
{
public:
    Sun();
    Sun(qreal ylimit);
    ~Sun();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void advance(int stage) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

public:
    static constexpr qreal dropSpeed = 120.0; // pixel per sec
    static constexpr int lifespan = 15; // in sec

private:
    QMovie* movie;
    qreal stopY;
    int lifetime;
};

#endif // SUN_H
