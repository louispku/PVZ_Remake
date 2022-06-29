#ifndef SEEDBANK_H
#define SEEDBANK_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QVector>
#include "seedpacket.h"

// 植物栏
class SeedBank : public QGraphicsItem
{
public:
    SeedBank(const QVector<int>& plants);
    //~Seedbank();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void advance(int stage) override;

public:
    int sun;
    bool selected;

private:
    QPixmap* pixmap;
};

#endif // SEEDBANK_H
