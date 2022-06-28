#ifndef SEEDPACKET_H
#define SEEDPACKET_H

#include <QGraphicsItem>
#include <QPixmap>

class SeedPacket : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    SeedPacket(int plant, QGraphicsItem *parent = nullptr);
    ~SeedPacket();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void advance(int stage) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void plantSelected(int plantTy);

public:
    const int plantType;
    int counter;

private:
    QPixmap *background;
    QPixmap *plantImage;
};

#endif // SEEDPACKET_H
