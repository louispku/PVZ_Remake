#include "mainwindow.h"
#include "plantselectwindow.h"
#include "battleWindow.h"
#include "selectwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    cur_interface = new SelectWindow(this);
    connect(reinterpret_cast<SelectWindow*>(cur_interface), &SelectWindow::plantSelectStart, this, &mapSelectToPlantSelect);
    cur_interface->setFixedSize(900, 600);
    cur_interface->show();
}

MainWindow::~MainWindow()
{

}

void MainWindow::plantSelectToGame(QVector<int> selected)
{
    cur_interface->close();
    //delete cur_interface;
    cur_interface = new BattleWindow(mapType, selected, this);
    cur_interface->setFixedSize(900, 600);
    cur_interface->show();
}

void MainWindow::mapSelectToPlantSelect(BattleWindow::MapType mapTy)
{
    mapType = mapTy;
    cur_interface->close();
    //delete cur_interface;
    cur_interface = new PlantSelectWindow(this);
    cur_interface->setFixedSize(900, 600);
    cur_interface->show();
}
