#ifndef CONEZOMBIE_H
#define CONEZOMBIE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "basic_zombie.h"
#include "config.h"

class ConeZombie : public Basic_Zombie
{
public:
    ConeZombie();
    void advance(int phase) override;
};

#endif // CONEZOMBIE_H
