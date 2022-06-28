#ifndef MAP_H
#define MAP_H

#include <QGraphicsItem>
#include "basic_plant.h"

class Grid : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    Basic_Plant *plantGrid[9][5];
    int expectPlant;

public:
    static constexpr qreal xunit = 83.0;
    static constexpr qreal yunit = 96.0;

public slots:
    void waitPlant(int plantTy);

public:
    Grid();
    ~Grid();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QPoint atGrid(QPointF itemCoord) const;
    QPointF atScene(QPoint gridCoord) const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // MAP_H
