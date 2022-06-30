#include "basic_zombie.h"

#include "basic_plant.h"

#include <QDebug>

Basic_Zombie::Basic_Zombie():hp(0),atk(0),speed(0.0)
{
    movie = nullptr;
    head = nullptr;
}

Basic_Zombie::~Basic_Zombie()
{
    delete movie;
    delete head;
}

void Basic_Zombie::attacked(int damage, int type)
{
    switch (type)
    {
    case Basic_Plant::Bomb:
        hp = 0;
        state = 3;
        break;

    case Basic_Plant::Mine:
        hp -= damage;
        state = 4;
        break;

    default:
        hp -= damage;
    }
}

QRectF Basic_Zombie::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

void Basic_Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)
    Q_UNUSED(option)

    QImage cur_image = movie->currentImage();

    if (speed < 0.55 && state != 3)
    {
        if (state != 2)
            movie->setSpeed(50);
        int R = cur_image.width();
        int C = cur_image.height();
        for (int i = 0; i < R; ++i)
        {
            uchar *line = cur_image.scanLine(i);
            for (int j = 5; j < C - 5; ++j)
                line[j << 2] = 200;
        }
    }
    painter->drawImage(QRectF(-70, -100, 140, 140), cur_image);
    if (head)
    {
        cur_image = head->currentImage();
        if (speed < 0.55)
        {
            int R = cur_image.width();
            int C = cur_image.height();
            for (int i = 0; i < R; ++i)
            {
                uchar *setline = cur_image.scanLine(i);
                for (int j = 5; j < C - 5; ++j)
                    setline[j << 2] = 200;
            }
        }
        painter->drawImage(QRectF(0, -100, 140, 140), cur_image);
    }
}


int Basic_Zombie::type() const
{
    return Type;
}

void Basic_Zombie::setMovie(QString  gifPath)
{
    if (movie)
        delete movie;
    movie = new QMovie(gifPath);
    movie->start();
}

void Basic_Zombie::setHead(QString  gifPath)
{
    if (head)
        delete head;
    head = new QMovie(gifPath);
    head->start();
}

bool Basic_Zombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    if(other->type() == Basic_Plant::Type
            && qFuzzyCompare(other->y(), y())
            && qAbs(other->x() - x()) < 30){
        return true;
    }
    else return false;
}
