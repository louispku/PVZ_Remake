#ifndef TEXT_H
#define TEXT_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QString>
#include <QRectF>
#include <QFont>
class Text : public QGraphicsItem
{
private:
    int plantNum;
    QString texttoPaint;

public:

    Text(QString);
    QRectF boundingRect()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


};

#endif // TEXT_H
