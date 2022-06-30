#ifndef BUCKETZOMBIE_H
#define BUCKETZOMBIE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <basic_zombie.h>
#include "config.h"

class BucketZombie : public Basic_Zombie
{
public:
    BucketZombie();
    void advance(int phase) override;
};

#endif // BUCKETZOMBIE_H
