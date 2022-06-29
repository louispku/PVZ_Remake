#include "initialwindow.h"
#include "config.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QMouseEvent>

InitialWindow::InitialWindow(QWidget *parent)
    : QWidget(parent)
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0.0, 0.0, 900.0, 600.0);
    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(RESOURCE_PATH + "/images/interface/Surface.png"));
    view->show();
}

void InitialWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
       {
           qDebug()<<event->pos().y();
           if((event->pos().x()>453)&&(event->pos().x()<816)&&(event->pos().y()>56)&&(event->pos().y()<150)){
               setCursor(Qt::OpenHandCursor);
               emit
           }
       }
}
InitialWindow::~InitialWindow()
{
    delete view;
    view = nullptr;
    delete scene;
    scene = nullptr;
}

