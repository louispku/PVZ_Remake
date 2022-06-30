#include "mainwindow.h"
#include "battleWindow.h"
#include "selectwindow.h"
#include "config.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto mainwindow = new SelectWindow(this);
    mainwindow->setFixedSize(900, 600);
    mainwindow->show();
}

MainWindow::~MainWindow()
{

}

