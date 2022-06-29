#ifndef SHOVELBANK_H
#define SHOVELBANK_H

#include <QGraphicsItem>
#include <QPixmap>

class ShovelBank : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    ShovelBank();
    ~ShovelBank();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void advance(int stage) override;

signals:
    void shovelSelected(int type);

public slots:
    //void deselect();

protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

public:
    QPixmap *background;
    QPixmap *shovelImage;
    bool selected;
};

#endif // SHOVELBANK_H
