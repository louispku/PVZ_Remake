#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QEvent>
#include <QMouseEvent>

class SelectWindow : public QWidget
{
public:
    QGraphicsScene *scene;
    QGraphicsView *view;
    SelectWindow(QWidget *parent = nullptr);
    ~SelectWindow();
    void mousePressEvent(QMouseEvent * event);
};

#endif // SELECTWINDOW_H
