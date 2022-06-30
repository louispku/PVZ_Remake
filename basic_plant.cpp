#include "basic_plant.h"
#include "battlewindow.h"
#include "qgraphicsscene.h"

Basic_Plant::Basic_Plant(QGraphicsItem* parent) : QGraphicsItem(parent), movie(nullptr)
{
}

Basic_Plant::~Basic_Plant()
{
    if (movie)
    {
        delete movie;
    }
}

QRectF Basic_Plant::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

int Basic_Plant::type() const
{
    return Type;
}

void Basic_Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(boundingRect(), movie->currentImage());
}

void Basic_Plant::setMovie(const QString &path)
{
    if (movie)
    {
        delete movie;
    }
    movie = new QMovie(path);
    movie->start();
}

bool Basic_Plant::isMushroom() const
{
    return false;
}

void Basic_Plant::deleteSelf()
{
    reinterpret_cast<BattleWindow*>(scene()->parent())->removePlant(this);
    delete this;
}
