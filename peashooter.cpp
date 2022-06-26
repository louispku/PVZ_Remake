#include "peashooter.h"
#include "basic_zombie.h"

bool Peashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const
{
    return qFuzzyCompare(y(), other->y())
           &&
           other->type() == Basic_Zombie::Type;
}
