#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include "basic_plant.h"
#include "grid.h"
#include "seedbank.h"
#include "shovelbank.h"
#include "sun.h"
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
    SeedBank* seedbank;
    ShovelBank* shovelbank;
    Grid* grid;


public:
    BattleWindow(MapType mapTy, QWidget* parent = nullptr);
    ~BattleWindow();
    Basic_Plant* addPlant(int plantType, QPointF pos);
    void removePlant(Basic_Plant* plant);

private:
    Sun* produceSun();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
};

#endif // BATTLEWINDOW_H
