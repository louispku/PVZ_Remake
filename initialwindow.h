#ifndef INITIALWINDOW_H
#define INITIALWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QEvent>
#include <QMouseEvent>

class InitialWindow : public QWidget
{
public:
    InitialWindow(QWidget *parent = nullptr);
    ~InitialWindow();
    QGraphicsScene *scene;
    QGraphicsView *view;
    void mousePressEvent(QMouseEvent * event);

};
#endif // INITIALWINDOW_H
