#include "mainwindow.h"
#include "battlewindow.h"
#include "selectwindow.h"
#include "initialwindow.h"
#include "config.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto mainwindow = new InitialWindow(this);
    mainwindow->setFixedSize(900, 600);
    mainwindow->show();
}

MainWindow::~MainWindow()
{

}

