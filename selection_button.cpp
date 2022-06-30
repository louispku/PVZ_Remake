#include "selection_button.h"
#include <QPainter>
#include <QPoint>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <vector>
#include "config.h"

const QMap<QString,int> Selection_Button::map={
    {"Peashooter",0},{"SunFlower",1},{"CherryBomb",2},
    {"WallNut",3},{"PotatoMine",4},{"SnowPea",5},
    {"Repeater",6},{"Puffshroom",7},{"Sunshroom",8},
    {"Fumeshroom",9},{"Coffeebean",10}
};


const QVector<QString> Selection_Button::name ={
    "Peashooter","SunFlower","CherryBomb",
    "WallNut","PotatoMine","SnowPea",
    "Repeater","Puffshroom","Sunshroom",
    "Fumeshroom","Coffeebean"
};

const QVector<qreal> Selection_Button::x ={
  350.0,350.0+106.0,350.0+2*106.0,350.0+3*106.0,350.0+4*106.0,0.0,
  350.0,350.0+106.0,350.0+2*106.0,350.0+3*106.0,350.0+4*106.0,

};

const QVector<qreal> Selection_Button::y ={
  350.0,350.0,350.0,350.0,350.0,0.0,
  420.0,420.0,420.0,420.0,420.0,


};
int Selection_Button::counter = 0;
QVector<int> Selection_Button::plant_list;

QString Selection_Button::cur = "";
Selection_Button::Selection_Button(QString s,int k):text(s),state(0),kind(k)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setAcceptedMouseButtons(Qt::LeftButton);
    this->setAcceptHoverEvents(true);

}


QRectF Selection_Button::boundingRect() const
{
    if(kind==0){
        return QRectF(-52.5, -31.5, 105.0, 63.0);
    }
    else if(kind==1){
        return QRectF(-52.5, -300.0, 105.0, 600.0);

    }
    else if(kind==2){
        return QRectF(-52.5, -31.5, 105.0, 63.0);
    }
}

void Selection_Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if(kind==0){
        if(state==0){

            painter->drawPixmap(-52.5,-31.5, QPixmap(RESOURCE_PATH + "/images/interface/" + text + ".png"));
        }
        else if(state==1){
            painter->drawPixmap(-52.5,-31.5, QPixmap(RESOURCE_PATH + "/images/interface/grey_" + text + ".png"));
        }


    }
    else if(kind==1){


        for(int i=0;i<plant_list.size();++i){
            int num = plant_list[i];
            QString tmp = name[num];
            painter->drawPixmap(-52.5, -220.0+80*i, QPixmap(RESOURCE_PATH + "/images/interface/" + tmp + ".png"));


        }
    }
    else if(kind==2){
        QString draw = Selection_Button::cur;
        QPixmap pixdraw(RESOURCE_PATH + "/images/interface/show_" + draw + ".png");
        painter->drawPixmap(-2-pixdraw.width()/2, -2-pixdraw.height()/2, pixdraw);

    }




}

/*void Selection_Button::paintOutside(QPainter *painter){
    QPointF selectPoint = this->mapFromScene(250.0,150.0);
    double x = selectPoint.rx();
    double y = selectPoint.ry();
    painter->drawPixmap(15.0,15.0,QPixmap("../PVZ_Remake/resources/images/interface/" + text + ".png"));
}*/


void Selection_Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if(kind==0){
        int judge=state;
        Selection_Button::cur = text;
        if(judge==0 && plant_list.size()<6){
            counter++;
            plant_list.push_back(map[cur]);
            state=1-state;
        }
        else if(judge==1 && plant_list.size()<=6){
            counter--;
            int num = map[cur];
            auto iter = plant_list.begin();
            while(iter!=plant_list.end()){
                if(*iter==num){
                    plant_list.erase(iter);
                }
                else iter++;
            }
            state=1-state;

        }

    }
}
