#include "grid.h"
#include "battlewindow.h"
#include "config.h"
#include <cstring>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>


void Grid::waitPlant(int plantTy)
{
    expectPlant = plantTy;
}

Grid::Grid() : expectPlant(-1)
{
    memset(plantGrid, 0, sizeof(plantGrid));
}

Grid::~Grid()
{

}

QRectF Grid::boundingRect() const
{
    return QRectF(0.0, 0.0, 9 * xunit, 5 * yunit);
}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

QPoint Grid::atGrid(QPointF itemCoord) const
{
    return QPoint(itemCoord.x() / xunit, itemCoord.y() / yunit);
}

QPointF Grid::atScene(QPoint gridCoord) const
{
    return mapToScene((gridCoord.x() + 0.5) * xunit, (gridCoord.y() + 0.5) * yunit);
}

void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (expectPlant < 0 || event->button() != Qt::LeftButton)
    {
        return;
    }

    auto gridCoord = atGrid(event->pos());
    if (!plantGrid[gridCoord.x()][gridCoord.y()])
    {
        auto battlewindow = reinterpret_cast<BattleWindow*>(scene()->parent());
        plantGrid[gridCoord.x()][gridCoord.y()] = battlewindow->addPlant(expectPlant, atScene(gridCoord));
        auto seedbank = qgraphicsitem_cast<SeedBank*>(scene()->items(QPointF(300, 15))[0]);
        seedbank->sun -= Cost[expectPlant];
        seedbank->selected = false;
        battlewindow->setCursor(Qt::ArrowCursor);

        for (auto p : seedbank->childItems())
        {
            auto seedpacket = qgraphicsitem_cast<SeedPacket*>(p);
            if (seedpacket->plantType == expectPlant)
            {
                seedpacket->counter = 0;
            }
        }

        expectPlant = -1;
    }
}
