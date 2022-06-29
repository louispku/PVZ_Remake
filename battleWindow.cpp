#include "battlewindow.h"
#include "seedbank.h"
#include "sun.h"
#include "pea.h"
#include "peashooter.h"
#include "zombie.h"
#include "grid.h"
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

    seedbank = new SeedBank({PEASHOOTER, SUNFLOWER});
    seedbank->setPos(520.0, 45.0);
    scene->addItem(seedbank);

    shovelbank = new ShovelBank;
    shovelbank->setPos(800.0, 0.0);
    scene->addItem(shovelbank);

    grid = new Grid;
    grid->setPos(250.0, 92.0);
    scene->addItem(grid);
    for (auto packet : seedbank->childItems())
    {
        connect(static_cast<SeedPacket*>(packet), &SeedPacket::plantSelected, grid, &Grid::setWaitFlag);
    }
    connect(shovelbank, &ShovelBank::shovelSelected, grid, &Grid::setWaitFlag);

    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &BattleWindow::produceSun);
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

Basic_Plant* BattleWindow::addPlant(int plantType, QPointF pos)
{
    Basic_Plant* plant;
    switch (plantType)
    {
    case PEASHOOTER:
        plant = new Peashooter; break;
    }

    plant->setPos(pos);
    scene->addItem(plant);
    return plant;
}

// without destroying the plant object
void BattleWindow::removePlant(Basic_Plant *plant)
{
    scene->removeItem(plant);
    auto gridCoord = grid->itemToGrid(grid->mapFromScene(plant->scenePos()));
    grid->plantAtGrid(gridCoord) = nullptr;
}

Sun* BattleWindow::produceSun()
{
    static constexpr int interval = 10;
    static int counter = FPS * interval;
    Sun* sun = nullptr;
    if (counter >= FPS * interval)
    {
        sun = new Sun;
        sun->setPos(300.0 + 600.0 * (qreal)rand() / RAND_MAX, -50.0);
        scene->addItem(sun);
        counter = 0;
    }
    else
    {
        counter++;
    }
    return sun;
}
