#include "fumeshroom.h"
#include "config.h"
#include "basic_zombie.h"

FumeShroom::FumeShroom(BattleWindow::MapType mapType) : Mushroom(mapType)
{
    state = 0;
    hp = init_hp;
    attack_counter = 0;
    anime_counter = 0;
    if (awake)
    {
        setMovie(RESOURCE_PATH + "/images/plants/FumeShroom/FumeShroom.gif");
    }
    else
    {
        setMovie(RESOURCE_PATH + "/images/plants/FumeShroom/FumeShroomSleep.gif");
    }

    for (int i = 0; i < 8; i++)
    {
        bullets[i] = new QPixmap(RESOURCE_PATH + "/images/plants/FumeShroom/FumeShroomBullet_" + QString().setNum(i+1) + ".png");
    }
}

FumeShroom::~FumeShroom()
{
    for (int i = 0; i < 8; i++)
    {
        delete bullets[i];
    }
}

QRectF FumeShroom::boundingRect() const
{
    return QRectF(-35, -35, 70 + 350, 70);
}

void FumeShroom::advance(int phase)
{
    if (phase == 0)
    {
        return;
    }
    update();

    if (hp <= 0)
    {
        deleteSelf();
        return;
    }

    if (!awake)
    {
        return;
    }

    if (state == 1)
    {
        if (anime_counter <= 15)
        {
            anime_counter++;
        }
        else
        {
            anime_counter = 0;
            state = 0;
        }

    }

    if (attack_counter >= FPS * attack_interval / 1000)
    {
        auto cldlist = scene()->items(x(), y(), attack_distance, 10.0, Qt::IntersectsItemBoundingRect, Qt::AscendingOrder);
        for (auto item : cldlist)
        {
            if (item->type() == Basic_Zombie::Type && qFuzzyCompare(y(), item->y()))
            {
                qgraphicsitem_cast<Basic_Zombie*>(item)->attacked(atk, Penetrate);
                attack_counter = 0;
                state  = 1;
            }
        }
    }
    else
    {
        attack_counter++;
    }
}

void FumeShroom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(QRectF(-35, -35, 70, 70), movie->currentImage());
    if (state == 1)
    {
        if (anime_counter <= 15)
        {
            painter->drawImage(QRectF(35, -35, attack_distance, 60), bullets[anime_counter / 2]->toImage());
        }
    }
}

void FumeShroom::wakeup()
{
    awake = true;
    setMovie(RESOURCE_PATH + "/images/plants/FumeShroom/FumeShroom.gif");
}
