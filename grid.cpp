#include "grid.h"
#include "battlewindow.h"
#include "config.h"
#include <cstring>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>


void Grid::setWaitFlag(int plantTy)
{
    waitFlag = plantTy;
}

Grid::Grid() : waitFlag(-1)
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
    if (waitFlag == -1 || event->button() != Qt::LeftButton)
    {
        return;
    }

    auto gridCoord = atGrid(event->pos());
    if (waitFlag >= 0 && !plantGrid[gridCoord.x()][gridCoord.y()])
    {
        auto battlewindow = reinterpret_cast<BattleWindow*>(scene()->parent());
        plantGrid[gridCoord.x()][gridCoord.y()] = battlewindow->addPlant(waitFlag, atScene(gridCoord));
        battlewindow->seedbank->sun -= Cost[waitFlag];
        battlewindow->seedbank->selected = false;
        battlewindow->setCursor(Qt::ArrowCursor);

        for (auto p : battlewindow->seedbank->childItems())
        {
            auto seedpacket = qgraphicsitem_cast<SeedPacket*>(p);
            if (seedpacket->plantType == waitFlag)
            {
                seedpacket->counter = 0;
            }
        }

        waitFlag = -1;
    }
    else if (waitFlag == -2 && plantGrid[gridCoord.x()][gridCoord.y()])
    {
         auto battlewindow = reinterpret_cast<BattleWindow*>(scene()->parent());
         battlewindow->removePlant(plantGrid[gridCoord.x()][gridCoord.y()]);
         delete plantGrid[gridCoord.x()][gridCoord.y()];
         plantGrid[gridCoord.x()][gridCoord.y()] = nullptr;
         battlewindow->shovelbank->selected = false;
         battlewindow->setCursor(Qt::ArrowCursor);
    }
}
