#include "seedpacket.h"
#include "battlewindow.h"
#include "seedbank.h"
#include "config.h"
#include <QPainter>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneEvent>

SeedPacket::SeedPacket(int plant, QGraphicsItem *parent)
    : QGraphicsItem(parent), plantType(plant),
      counter(CoolDown[plant] * FPS)
{
    background = new QPixmap(RESOURCE_PATH + "/images/interface/SeedPacket_Smaller.png");
    plantImage = new QPixmap(RESOURCE_PATH + "/images/plants/" + PlantName[plantType] + "/0.png");
}

SeedPacket::~SeedPacket()
{
    delete background;
    delete plantImage;
}

QRectF SeedPacket::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void SeedPacket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140), *background);
    painter->drawPixmap(QRect(-35, -42, 70, 70), *plantImage);
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(-30, 60, QString().sprintf("%3d", Cost[plantType]));
    if (counter < CoolDown[plantType] * FPS)
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 132 * (1 - qreal(counter) / (CoolDown[plantType] * FPS))));
    }
}

void SeedPacket::advance(int stage)
{
    if (stage == 0)
    {
        return;
    }

    update();

    if (counter < CoolDown[plantType] * FPS)
    {
        counter++;
    }
}

void SeedPacket::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton ||
        counter < CoolDown[plantType] * FPS ||
        qgraphicsitem_cast<SeedBank*>(parentItem())->sun < Cost[plantType])
    {
        return;
    }

    bool& selected = qgraphicsitem_cast<SeedBank*>(parentItem())->selected;

    if (selected)
    {
        selected = false;
        emit plantSelected(-1); // map not waiting for a plant
        reinterpret_cast<QWidget*>(scene()->parent())
                ->setCursor(Qt::ArrowCursor);
    }
    else
    {

        selected = true;
        emit plantSelected(plantType);
        reinterpret_cast<QWidget*>(scene()->parent())
                ->setCursor(QCursor(*plantImage));
    }

}


