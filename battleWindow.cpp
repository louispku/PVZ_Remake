#include "battlewindow.h"
#include "cherrybomb.h"
#include "fumeshroom.h"
#include "potatomine.h"
#include "puff.h"
#include "puffshroom.h"
#include "repeater.h"
#include "seedbank.h"
#include "sun.h"
#include "pea.h"
#include "peashooter.h"
#include "sunflower.h"
#include "sunshroom.h"
#include "wallnut.h"
#include "zombie.h"
#include "conezombie.h"
#include "bucketzombie.h"
#include "footballzombie.h"
#include "screenzombie.h"
#include "grid.h"
#include "config.h"
#include "QDebug"

BattleWindow::BattleWindow(MapType mapTy, QVector<int> selected, QWidget *parent) : QWidget(parent), mapType(mapTy)
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

    seedbank = new SeedBank(selected);
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
    if (mapType == DAY)
    {
        connect(timer, &QTimer::timeout, this, &BattleWindow::produceSun);
    }
    connect(timer, &QTimer::timeout, this ,&BattleWindow::addZombie);
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
    case SUNFLOWER:
        plant = new SunFlower; break;
    case WALLNUT:
        plant = new WallNut; break;
    case CHERRYBOMB:
        plant = new CherryBomb; break;
    case POTATOMINE:
        plant = new PotatoMine; break;
    case REPEATER:
        plant = new Repeater; break;
    case PUFFSHROOM:
        plant = new PuffShroom(mapType); break;
    case SUNSHROOM:
        plant = new SunShroom(mapType); break;
    case FUMESHROOM:
        plant = new FumeShroom(mapType); break;

    default:
        qDebug() << "No suitable plant\n";
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

void BattleWindow::addZombie(){

    static int lowerbound = 4;
    static int higherbound = 8;

    static int maxtime = 20 * 1000 / 33;
    static int time = maxtime / 2;

    static int counter = 0;
    if (++counter >= time)
    {
        if (++lowerbound > higherbound)
        {
            maxtime /= 1.3;
            higherbound *= 2;
        }
        counter = 0;
        time = qrand() % (2 * maxtime / 3) + maxtime / 3;

        int road = qrand() % 5;

        int type = qrand() % 100;

        Basic_Zombie *basic_zombie;
        if (type < 40)
            basic_zombie = new Zombie;
        else if (type < 70)
            basic_zombie = new ConeZombie;
        else if (type < 80)
            basic_zombie = new BucketZombie;
        else if (type < 90)
            basic_zombie = new ScreenZombie;
        else
            basic_zombie = new FootballZombie;

        auto pos = grid->gridToScene(QPoint(9, road));
        pos.setX(1010.0);
        basic_zombie->setPos(pos);
        scene->addItem(basic_zombie);
        }
}
