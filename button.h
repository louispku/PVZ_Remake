#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsItem>

class Button : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Button();
    ~Button();

protected:
    QPixmap* pixmap;
};

#endif // BUTTON_H
