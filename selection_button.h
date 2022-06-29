#ifndef SELECTION_BUTTON_H
#define SELECTION_BUTTON_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QString>
#include <QPainter>

class Selection_Button : public QGraphicsItem
{
public:

    QString text;
    int state;//0代表未选 1代表已经选择
    int kind;//0代表按钮 1代表选择栏 2代表图片展示栏
    static int counter;
    static QString cur;
    static std::vector<int> plant_list;//选中的植物列表
    const static QMap<QString,int> map;
    const static QVector<QString> name;
    const static QVector<qreal> x;
    const static QVector<qreal> y;

    Selection_Button(QString s,int k);
    QRectF boundingRect() const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) override ;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void paintOutside(QPainter *painter);

};

#endif // SELECTION_BUTTON_H
