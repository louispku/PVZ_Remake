#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QEvent>
#include <QMouseEvent>
#include "battleWindow.h"

class SelectWindow : public QWidget
{
    Q_OBJECT
public:
    QGraphicsScene *scene;
    QGraphicsView *view;
    SelectWindow(QWidget *parent = nullptr);
    ~SelectWindow();
    void mousePressEvent(QMouseEvent * event);

signals:
    void plantSelectStart(BattleWindow::MapType mapType);
};

#endif // SELECTWINDOW_H
