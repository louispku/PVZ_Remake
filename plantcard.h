#ifndef PLANTCARD_H
#define PLANTCARD_H

#include "basic_widget.h"

class PlantCard : public Basic_Widget
{
public:
    int counter;
    QString text;//name of the plant
    PlantCard(QString s);
    const static QMap<QString, int> map;
    const static QVector<QString> name;
    const static QVector<int> cost;
    const static QVector<int> wait;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
};

#endif // PLANTCARD_H
