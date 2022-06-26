#ifndef BASIC_WIDGET_H
#define BASIC_WIDGET_H

#include <QGraphicsItem>

// base class of any item other than plants and zombies
class Basic_Widget : public QGraphicsItem
{
public:
    enum { Type = UserType + 3 };

public:
    int type() const override;
};

#endif // BASIC_WIDGET_H
