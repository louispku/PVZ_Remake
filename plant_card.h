#ifndef PLANT_CARD_H
#define PLANT_CARD_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QString>
#include <QMovie>
#include <QRectF>
#include <QPixmap>

//用来显示植物卡片背景
class Plant_Card : public QGraphicsItem
{

private:
    QPixmap pix;
public:

    Plant_Card(QPixmap *pixmap);
    ~Plant_Card();


    QRectF boundingRect()const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;

};

#endif // PLANT_CARD_H
