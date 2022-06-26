#ifndef ZOMBIE_H
#define ZOMBIE_H


#include "basic_zombie.h"

//普通僵尸
class Zombie : public Basic_Zombie
{
public:
    Zombie();
    void advance(int phase) override;
};

#endif
