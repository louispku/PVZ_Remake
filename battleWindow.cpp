#include "battlewindow.h"
#include "seedbank.h"
#include "pea.h"
#include "peashooter.h"
#include "zombie.h"
#include "config.h"

BattleWindow::BattleWindow(MapType mapTy, QWidget *parent) : QWidget(parent), mapType(mapTy)
{
    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    switch(mapType)
    {
    case DAY:
        scene->setBackgroundBrush(QPixmap(RESOURCE_PATH + "/images/interface/background1.jpg"));
        break;
    case NIGHT:
        scene->setBackgroundBrush(QPixmap(RESOURCE_PATH + "/images/interface/background2.jpg"));
        break;
    }
    scene->setSceneRect(150.0, 0.0, 900.0, 600.0);

    auto seedbank = new SeedBank;
    seedbank->setPos(520.0, 45.0);
    scene->addItem(seedbank);

    auto ps = new Peashooter;
    ps->setPos(300.0, 300.0);

    auto pe = new Pea;
    pe->setPos(350.0,300.0);

    auto zb = new Zombie;
    zb->setPos(900.0,300.0);

    scene->addItem(ps);
    scene->addItem(zb);
    scene->addItem(pe);

    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(1000 / FPS);
    view->show();
}

BattleWindow::~BattleWindow()
{
    delete view;
    view = nullptr;
    delete scene;
    scene = nullptr;
}
