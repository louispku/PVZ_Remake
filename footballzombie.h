#ifndef FOOTBALLZOMBIE_H
#define FOOTBALLZOMBIE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <basic_zombie.h>
#include "config.h"

class FootballZombie : public Basic_Zombie
{
public:
    FootballZombie();
    void advance(int phase) override;
};

#endif // FOOTBALLZOMBIE_H
