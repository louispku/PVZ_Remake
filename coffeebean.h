#ifndef COFFEEBEAN_H
#define COFFEEBEAN_H

#include "config.h"
#include "basic_plant.h"
#include "mushroom.h"

class CoffeeBean : public Basic_Plant
{
public:
    enum { Type = UserType + COFFEEBEAN };
    int type() const override;

    CoffeeBean(Mushroom* sleepMushroom);
    void advance(int phase) override;
    QRectF boundingRect() const override;

public:
    static constexpr int wait = 1; // in sec

private:
    Mushroom *to_wake;
    int state;
    int counter;
};

#endif // COFFEEBEAN_H
