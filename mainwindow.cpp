#include "mainwindow.h"
#include "config.h"
#include "pea.h"
#include "peashooter.h"
#include "zombie.h"
#include <QDebug>
#include <QObject>
#include <QAction>
#include <QPixmap>
#include <QString>
#include "plant_card.h"
#include "text.h"
#include "selection_button.h"
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    /*

        timer = new QTimer(this);
        scene = new QGraphicsScene(this);
        scene->setSceneRect(150.0, 0.0, 900.0, 600.0);
        auto ps = new Peashooter;
        ps->setPos(300.0, 300.0);

        auto pe = new Pea;
        pe->setPos(350.0,300.0);

        auto zb = new Zombie;
        zb->setPos(800.0,300.0);

        scene->addItem(ps);
        scene->addItem(zb);
        scene->addItem(pe);


        view = new QGraphicsView(scene, this);
        view->resize(902, 602);
        view->setRenderHint(QPainter::Antialiasing);
        view->setBackgroundBrush(QPixmap("../PVZ_Remake/resources/images/interface/background1.jpg"));
        view->setCacheMode(QGraphicsView::CacheBackground);
        view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

        connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
        timer->start(1000 / FPS);
        view->show();
    */


        scene = new QGraphicsScene;
        scene->setSceneRect(0.0, 0.0, 900.0, 600.0);

        //initScene();
        //设置植物信息显示框
        pixmap = new QPixmap("../PVZ_Remake/resources/images/interface/AwardScreen_Back_mid.jpg");
        card = new Plant_Card(pixmap);
        scene->addItem(card);
        card->setPos(550.0,200.0);
        //标题
        QString str = "Plant Selection";
        text = new Text(str);
        scene->addItem(text);
        text->setPos(450.0,90.0);
        //已选列表
        choose = new Selection_Button("",1);
        scene->addItem(choose);
        choose->setPos(180.0,300.0);



        //添加植物

        for(int i=0;i<=10;i++){
            select[i] = new Selection_Button(Selection_Button::name[i],0);
            scene->addItem(select[i]);
            select[i]->setPos(Selection_Button::x[i],Selection_Button::y[i]);

        }




        /*select = new Selection_Button("Peashooter",0);
        scene->addItem(select);
        select->setPos(450.0,450.0);
        */
        //添加显示图元
        screen = new Selection_Button("",2);
        scene->addItem(screen);
        screen->setPos(550.0,200.0);

        view = new QGraphicsView(scene,this);
        view->resize(902,602);
        view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        view->setBackgroundBrush(QPixmap("../PVZ_Remake/resources/images/interface/Almanac_PlantBack.jpg"));
        view->show();


}












MainWindow::~MainWindow()
{   if(view){
        delete view;
        view = nullptr;
    }
    if(scene){
        delete scene;
        scene = nullptr;
    }
    if(pixmap){
        delete pixmap;
        pixmap = nullptr;
    }
    if(text){
        delete text;
        text = nullptr;
    }
    if(card){
        delete card;
        card = nullptr;
    }

    if(choose){
        delete choose;
        choose = nullptr;
    }
    if(screen){
        delete screen;
        screen = nullptr;
    }
    delete [] select;
}

