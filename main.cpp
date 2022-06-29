#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(nullptr);
    w.setFixedSize(900, 600);
    w.setWindowTitle("PVZ Remake");

    w.show();
    return a.exec();
}
