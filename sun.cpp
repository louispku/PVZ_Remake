#include "sun.h"
#include "config.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include "battlewindow.h"
#include "qdebug.h"

Sun::Sun() : lifetime(0)
{
    movie = new QMovie(RESOURCE_PATH + "/images/interface/Sun.gif");
    movie->start();
    stopY = 200.0 * (qreal)rand() / RAND_MAX + 200.0;
}

Sun::~Sun()
{
    delete movie;
}

QRectF Sun::boundingRect() const
{
    return QRectF(-38.0, -38.0, 76.0, 76.0);
}

void Sun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawImage(boundingRect(), movie->currentImage());
}

void Sun::advance(int stage)
{
    if (stage == 0)
    {
        return;
    }

    update();

    if (lifetime > lifespan * FPS)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    else
    {
        lifetime++;
    }

    if (y() < stopY)
    {
        qDebug() << x() << "," << y() << endl;
        setY(y() + dropSpeed / FPS);
    }
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
    {
        return;
    }

    reinterpret_cast<BattleWindow*>(scene()->parent())->seedbank->sun += 25;
    scene()->removeItem(this);
    delete(this);
}
