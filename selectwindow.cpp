#include "selectwindow.h"
#include "config.h"
#include <QMouseEvent>
#include <QGraphicsTextItem>
#include <QEvent>
#include <QDebug>

SelectWindow::SelectWindow(QWidget *parent): QWidget(parent)
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0.0, 0.0, 900.0, 600.0);
    scene->setBackgroundBrush(QPixmap(RESOURCE_PATH + "/images/interface/Almanac_IndexBack.jpg"));
    QGraphicsTextItem *title = new QGraphicsTextItem();
    title->setPos(300, 20);
    title->setPlainText("Select a Scene");
    title->setFont(QFont("Consolas", 18, QFont::Bold));
    title->setZValue(30);

    scene->addItem(title);
    QGraphicsRectItem *m1 = new QGraphicsRectItem();
    QGraphicsRectItem *m2 = new QGraphicsRectItem();
    m1->setRect(-180, -180, 180, 180);
    m1->setPos(330,385);
    m1->setBrush(QPixmap(RESOURCE_PATH + "/images/interface/zombatar_background_menu_dos.png"));
    scene->addItem(m1);
    m2->setRect(-180, -180, 180, 180);
    m2->setPos(760,385);
    m2->setBrush(QPixmap(RESOURCE_PATH + "/images/interface/zombatar_background_menu.png"));
    scene->addItem(m2);
    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setRenderHint(QPainter::Antialiasing);
    view->show();

}

void SelectWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
       {
           if((event->pos().x()>152)&&(event->pos().x()<327)&&(event->pos().y()>209)&&(event->pos().y()<386)){
               setCursor(Qt::OpenHandCursor);
               emit plantSelectStart(BattleWindow::DAY);
           }
           else if((event->pos().x()>583)&&(event->pos().x()<758)&&(event->pos().y()>209)&&(event->pos().y()<386)){
               setCursor(Qt::OpenHandCursor);
               emit plantSelectStart(BattleWindow::NIGHT);
           }
       }
}
SelectWindow::~SelectWindow()
{
    delete view;
    view = nullptr;
    delete scene;
    scene = nullptr;
}
