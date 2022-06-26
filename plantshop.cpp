#include "plantshop.h"

//change plantcard
PlantShop::PlantShop()
{
    sun = 200;
    counter = 0;
    time = int(7.0 * 1000 / 33);
    PlantCard *plantcard = nullptr;
    for (int i = 0; i < PlantCard::name.size(); ++i)
    {
        plantcard = new PlantCard(PlantCard::name[i]);
        plantcard->setParentItem(this);
        plantcard->setPos(-157 + 65 * i, -2);
    }
}

//bounding
QRectF PlantShop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void PlantShop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-270, -45, 540, 90), QPixmap(":/resources/images/interface/Shop.png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
    painter->drawPoint(-220, 0);
}

void PlantShop::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new Sun);
    }
}

void PlantShop::addPlant(QString s, QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    foreach (QGraphicsItem *item, items)
        if (item->type() == Basic_Plant::Type)
            return;
    sun -= PlantCard::cost[PlantCard::map[s]];
    Basic_Plant *plant = nullptr;
    switch (PlantCard::map[s])
    {
    case 0:
        plant = new SunFlower; break;
    case 1:
        plant = new Peashooter; break;
    case 2:
        plant = new CherryBomb; break;
    case 3:
        plant = new WallNut; break;
    case 4:
        plant = new SnowPea; break;
    case 5:
        plant = new PotatoMine; break;
    case 6:
        plant = new Repeater; break;
    }
    plant->setPos(pos);
    scene()->addItem(plant);
    QList<QGraphicsItem *> child = childItems();
    foreach (QGraphicsItem *item, child)
    {
        PlantCard *card = qgraphicsitem_cast<PlantCard *>(item);
        if (card->text == s)
            card->counter = 0;
    }
    counter = 0;
}

