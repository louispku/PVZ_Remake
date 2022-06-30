#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "battleWindow.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void plantSelectToGame(QVector<int> selected);
    void mapSelectToPlantSelect(BattleWindow::MapType mapTy);

private:
    QWidget* cur_interface;
    BattleWindow::MapType mapType;

};
#endif // MAINWINDOW_H
