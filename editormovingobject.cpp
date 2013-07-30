#include "editormovingobject.h"

EditorMovingObject::EditorMovingObject(int x, int y, QString name,
                                       QObject *parent, QGraphicsItem *item) :
    QObject(parent), QGraphicsItem(item)
{ setFlags( QGraphicsItem::ItemIsMovable
            | QGraphicsItem::ItemIsSelectable
            | QGraphicsItem::ItemIsFocusable
            | QGraphicsItem::ItemSendsGeometryChanges
            );


   this->name=name;


   m_shape.addRect(0,0,175,30);
   setPos(x,y);


}

QRectF EditorMovingObject::boundingRect() const
{
QRectF r;


return m_shape.boundingRect();
}



void EditorMovingObject::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
//проверка на выделение если выделен - красный контур
if(isSelected())
{
   painter->setPen(Qt::red);
}
else
{
    painter->setPen(Qt::black);
}
/////////////////////////////////////////////////////


painter->drawPath(m_shape);//сформированный контур объекта
painter->setPen(Qt::black);

//painter->drawRect(boundingRect());

painter->drawText(m_shape.boundingRect(), name);//имя объекта
}


QVariant EditorMovingObject::itemChange(GraphicsItemChange change,
                                        const QVariant &value)//если объект изменился
{
    if((change==QGraphicsItem::ItemPositionHasChanged)&&(isSelected()))//
    {
    emit signal_itemChanged(this, 1);//если изменилась позиция объекта, шлем сигнал
    }

    if(change==QGraphicsItem::ItemSelectedChange)
    {

    }
    return value;
}



void EditorMovingObject::slot_itemPosChanged(EditorMovingObject *obj, int x, int y)
{
    qDebug()<<"сигнал принял!";
    if(this==obj)
    {
        //QObject::blockSignals(true);
        setPos(x,y);
        //QObject::blockSignals(false);
    }
}

void EditorMovingObject::slot_itemNameChanged(EditorMovingObject *obj, QString name)
{
    if(this==obj)
    {
        QObject::blockSignals(true);
        this->name=name;
        QObject::blockSignals(false);
    }
}


void EditorMovingObject::setName(QString name)
{
    this->name=name;
}
