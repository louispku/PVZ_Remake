#ifndef SEEDPACKET_H
#define SEEDPACKET_H

#include <QGraphicsItem>
#include <QPixmap>

class SeedPacket : QGraphicsItem
{
public:
    SeedPacket(int plant, QGraphicsItem *parent = nullptr);

public:
    const int plantType;

private:
    QPixmap *background;
    QPixmap *plantImage;
};

#endif // SEEDPACKET_H
