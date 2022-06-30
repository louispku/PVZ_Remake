#include "button.h"
#include "config.h"

Button::Button()
{
    pixmap = new QPixmap(RESOURCE_PATH + "/images/interface/Button_Play.png");
}

Button::~Button()
{
    delete pixmap;
}
