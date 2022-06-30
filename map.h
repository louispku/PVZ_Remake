#ifndef MAP_H
#define MAP_H

#include "basic_widget.h"
#include "basic_plant.h"

class Map : public Basic_Widget
{
private:
    Basic_Plant* mapGrid[5][9];

public:


public:
    Map();
    ~Map();


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

};

#endif // MAP_H
