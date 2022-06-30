#ifndef BASIC_PLANT_H
#define BASIC_PLANT_H

#include <QGraphicsItem>
#include <QMovie>
#include <QPainter>

// base class of any plant class
class Basic_Plant : public QGraphicsItem
{
public:
    enum { Type = UserType + 1 };
    enum DamageType
    {
        Normal = 0,
        Bomb = 1,
        Mine = 2,
        Penetrate = 3
    };

    int hp;

protected:
    QMovie* movie;

public:
    Basic_Plant(QGraphicsItem* parent = nullptr);
    virtual ~Basic_Plant();
    virtual QRectF boundingRect() const override;
    int type() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setMovie(const QString& path);
    virtual bool isMushroom() const;

protected:
    void deleteSelf();

};

#endif // BASIC_PLANT_H
