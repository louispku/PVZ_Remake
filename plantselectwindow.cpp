#include "plantselectwindow.h"
#include "battleWindow.h"
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
#include "switchbutton.h"
#include <QGraphicsView>

PlantSelectWindow::PlantSelectWindow(QWidget *parent)
    : QWidget(parent){

        scene = new QGraphicsScene(this);
        scene->setSceneRect(0.0, 0.0, 900.0, 600.0);

        //initScene();
        //设置植物信息显示框
        pixmap = new QPixmap(RESOURCE_PATH + "/images/interface/AwardScreen_Back_mid.jpg");
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

        auto switchbutton = new SwitchButton("PLAY!");
        switchbutton->setPos(700, 550);
        scene->addItem(switchbutton);
        connect(switchbutton, &SwitchButton::gameplay, reinterpret_cast<MainWindow*>(parent), &MainWindow::plantSelectToGame);

        //添加植物

        for(int i=0;i<=10;i++){
            select[i] = new Selection_Button(Selection_Button::name[i],0);
            if(i==5) continue;
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
        view->setBackgroundBrush(QPixmap(RESOURCE_PATH + "/images/interface/Almanac_PlantBack.jpg"));
        view->show();
}

PlantSelectWindow::~PlantSelectWindow()
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
}
