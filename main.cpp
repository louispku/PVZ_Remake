#include "mainwindow.h"
#include "initialwindow.h"
#include "selectwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SelectWindow w;
    w.setFixedSize(900, 600);
    w.setWindowTitle("PVZ Remake");

    w.show();
    return a.exec();
}
