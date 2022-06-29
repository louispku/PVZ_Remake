#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

class BattleWindow : public QWidget
{
    Q_OBJECT

public:
    enum MapType { DAY = 0, NIGHT = 1 };
    const MapType mapType;

public:
    BattleWindow(MapType mapTy, QWidget* parent = nullptr);
    ~BattleWindow();


private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
};

#endif // BATTLEWINDOW_H
