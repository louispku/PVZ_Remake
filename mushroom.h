#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "basic_plant.h"
#include "battleWindow.h"

class Mushroom : public Basic_Plant
{
public:
    Mushroom(BattleWindow::MapType mapType);
    bool isMushroom() const override;
    virtual void wakeup() = 0;

public:
    bool awake;


};

#endif // MUSHROOM_H
