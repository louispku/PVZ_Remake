#ifndef SCREENZOMBIE_H
#define SCREENZOMBIE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "Basic_zombie.h"
#include "config.h"

class ScreenZombie : public Basic_Zombie
{
public:
    ScreenZombie();
    void advance(int phase) override;
};

#endif // SCREENZOMBIE_H
