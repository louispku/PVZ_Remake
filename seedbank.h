#ifndef SEEDBANK_H
#define SEEDBANK_H

#include <QGraphicsItem>
#include <QPixmap>

// 植物栏
class SeedBank : public QGraphicsItem
{
public:
    SeedBank();
    //~Seedbank();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void advance(int stage) override;

public:
    int sun;

private:
    QPixmap* pixmap;
};

#endif // SEEDBANK_H
