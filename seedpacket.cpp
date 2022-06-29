#include "seedpacket.h"
#include "config.h"
#include <QMovie>

SeedPacket::SeedPacket(int plant, QGraphicsItem *parent) : QGraphicsItem(parent), plantType(plant)
{
    background = new QPixmap(RESOURCE_PATH + "/image/interface/SeedPacket_Smaller.png");
    plantImage = new QPixmap(QMovie(RESOURCE_PATH + "/image/plants/" + plantName[plantType] + "/0.gif").currentPixmap());
}
