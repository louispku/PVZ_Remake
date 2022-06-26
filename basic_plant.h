#ifndef BASIC_PLANT_H
#define BASIC_PLANT_H

#include <QGraphicsItem>
#include <QMovie>

// base class of any plant class
class Basic_Plant : public QGraphicsItem
{
public:
    enum { Type = UserType + 1 };

protected:
    int hp;

private:
    QMovie* movie;

public:
    Basic_Plant();
    virtual ~Basic_Plant();
    QRectF boundingRect() const override;
    int type() const override;
    void setMovie(const QString& path);

};

#endif // BASIC_PLANT_H
