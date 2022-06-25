#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(150.0, 0.0, 900.0, 600.0);


    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap("../PVZ_Remake/resources/images/interface/background1.jpg"));
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->show();
}

MainWindow::~MainWindow()
{
    delete view;
    view = nullptr;
    delete scene;
    scene = nullptr;
}

