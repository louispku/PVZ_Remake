#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include "button.h"

class SwitchButton : public Button
{
    Q_OBJECT
public:
    SwitchButton(const QString& str);
    // ~SwitchButton();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void gameplay(QVector<int> selected);

private:
    QString text;
    int state;
};

#endif // SWITCHBUTTON_H
