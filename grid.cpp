#include "grid.h"
#include "battlewindow.h"
#include "coffeebean.h"
#include "config.h"
#include "mushroom.h"
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

QPoint Grid::itemToGrid(QPointF itemCoord) const
{
    return QPoint(itemCoord.x() / xunit, itemCoord.y() / yunit);
}

QPointF Grid::gridToScene(QPoint gridCoord) const
{
    return mapToScene((gridCoord.x() + 0.5) * xunit, (gridCoord.y() + 0.5) * yunit);
}

Basic_Plant* &Grid::plantAtGrid(QPoint gridCoord)
{
    return plantGrid[gridCoord.x()][gridCoord.y()];
}

void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (waitFlag == -1 || event->button() != Qt::LeftButton)
    {
        return;
    }

    auto gridCoord = itemToGrid(event->pos());
    if (waitFlag >= 0 && waitFlag != COFFEEBEAN && !plantGrid[gridCoord.x()][gridCoord.y()])
    {
        auto battlewindow = reinterpret_cast<BattleWindow*>(scene()->parent());
        plantGrid[gridCoord.x()][gridCoord.y()] = battlewindow->addPlant(waitFlag, gridToScene(gridCoord));
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
    else if (waitFlag == COFFEEBEAN && plantGrid[gridCoord.x()][gridCoord.y()] && plantGrid[gridCoord.x()][gridCoord.y()]->isMushroom())
    {
        auto mushroom = qgraphicsitem_cast<Mushroom*>(plantGrid[gridCoord.x()][gridCoord.y()]);
        if (mushroom->awake)
        {
            return;
        }
        auto battlewindow = reinterpret_cast<BattleWindow*>(scene()->parent());
        auto coffeebean = new CoffeeBean(mushroom);
        coffeebean->setPos(0.0, 0.0);
        scene()->addItem(coffeebean);

        battlewindow->seedbank->sun -= Cost[COFFEEBEAN];
        battlewindow->seedbank->selected = false;
        battlewindow->setCursor(Qt::ArrowCursor);

        for (auto p : battlewindow->seedbank->childItems())
        {
            auto seedpacket = qgraphicsitem_cast<SeedPacket*>(p);
            if (seedpacket->plantType == COFFEEBEAN)
            {
                seedpacket->counter = 0;
            }
        }
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
