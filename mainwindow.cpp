#include "mainwindow.h"
#include "battlewindow.h"
#include "config.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto battlewindow = new BattleWindow(BattleWindow::NIGHT, this);
    battlewindow->setFixedSize(900, 600);
    battlewindow->show();
}

MainWindow::~MainWindow()
{

}

