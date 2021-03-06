#ifndef BASIC_ZOMBIE_H
#define BASIC_ZOMBIE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>

//僵尸基类
class Basic_Zombie : public QGraphicsItem
{

protected:
    QMovie *movie;
    QMovie *head;


public:
    int hp;
    int atk;
    double speed;

    int state; // 0-init, 1-eating, 2-dying, 3-die from bomb, 4-die from potatomine
    enum { Type = UserType + 2};

public:
    Basic_Zombie();
    ~Basic_Zombie() override;
    virtual void attacked(int damage, int type);
    int type() const override;


    void setMovie(QString  gifPath);
    void setHead(QString  gifPath);

    //渲染
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    //边界矩形
    QRectF boundingRect() const override;

    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;

};

#endif
