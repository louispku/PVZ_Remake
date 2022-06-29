#include "mainwindow.h"
#include "plantselectwindow.h"
#include "battlewindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    auto selectwindow = new PlantSelectWindow(this);
    selectwindow->setFixedSize(900, 600);
    selectwindow->show();
}

MainWindow::~MainWindow()
{

}
