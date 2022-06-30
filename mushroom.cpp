#include "mushroom.h"

Mushroom::Mushroom(BattleWindow::MapType mapType)
{
    if (mapType == BattleWindow::DAY)
    {
        awake = false;
    }
    else
    {
        awake = true;
    }
}

bool Mushroom::isMushroom() const
{
    return true;
}
