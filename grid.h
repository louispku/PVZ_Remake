#ifndef MAP_H
#define MAP_H

#include <QGraphicsItem>
#include "basic_plant.h"

class Grid : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    int waitFlag;
    Basic_Plant *plantGrid[9][5];

public:
    static constexpr qreal xunit = 83.0;
    static constexpr qreal yunit = 96.0;

public slots:
    void setWaitFlag(int plantTy);

public:
    Grid();
    ~Grid();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QPoint itemToGrid(QPointF itemCoord) const;
    QPointF gridToScene(QPoint gridCoord) const;
    Basic_Plant* &plantAtGrid(QPoint gridCoord);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // MAP_H
