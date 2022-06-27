#include "mainwindow.h"
#include "config.h"
#include "pea.h"
#include "peashooter.h"
#include "zombie.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(150.0, 0.0, 900.0, 600.0);

    auto ps = new Peashooter;
    ps->setPos(300.0, 300.0);

    auto pe = new Pea;
    pe->setPos(350.0,300.0);

    auto zb = new Zombie;
    zb->setPos(800.0,300.0);

    scene->addItem(ps);
    scene->addItem(zb);
    scene->addItem(pe);


    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap("../PVZ_Remake/resources/images/interface/background1.jpg"));
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(1000 / FPS);
    view->show();
}

MainWindow::~MainWindow()
{
    delete view;
    view = nullptr;
    delete scene;
    scene = nullptr;
}

