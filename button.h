#ifndef BUTTON_H
#define BUTTON_H

#include <QTimer>
#include <QSound>
#include "basic_widget.h"

class Button : public Basic_Widget
{
public:
    Button(QSound *s, QTimer *t);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QSound *sound;
    QTimer *timer;
};

#endif // BUTTON_H
