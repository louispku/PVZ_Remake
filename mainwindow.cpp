#include "mainwindow.h"
#include "plantselectwindow.h"
#include "battlewindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    cur_interface = new PlantSelectWindow(this);
    cur_interface->setFixedSize(900, 600);
    cur_interface->show();
}

MainWindow::~MainWindow()
{

}

void MainWindow::selectToGame(QVector<int> selected)
{
    cur_interface->close();
    //delete cur_interface;
    cur_interface = new BattleWindow(BattleWindow::DAY, selected, this);
    cur_interface->setFixedSize(900, 600);
    cur_interface->show();
}
