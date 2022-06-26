#ifndef BASIC_ZOMBIE_H
#define BASIC_ZOMBIE_H

#include <QGraphicsItem>

// base class of any zombie class
class Basic_Zombie : public QGraphicsItem
{
public:
    enum { Type = UserType + 2 };

public:
    int type() const override;
};

#endif // BASIC_ZOMBIE_H
