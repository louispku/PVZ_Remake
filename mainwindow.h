#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QMenuBar>
#include <QTimer>
#include <QPixmap>
#include <vector>
#include <text.h>
#include <selection_button.h>
#include <plant_card.h>

//在MainWindow里实现了选择界面 没有实现开始-选择界面-战斗界面 的切换
//合并分支时需要把这段代码改到某个MainWindow子类窗口中？
//"开始游戏"按钮 要在界面切换方式确定后再加入
class MainWindow: public QMainWindow
{
    Q_OBJECT

public:


    QPixmap *pixmap;            //用来加载图像
    Text *text;                 //用来加载文字
    Plant_Card *card;           //图片背景框
    Selection_Button *select[11];//植物卡片
    Selection_Button *choose;//左侧选择列表
    Selection_Button *screen;//显示植物

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    //QTimer *timer;












};
#endif // MAINWINDOW_H
