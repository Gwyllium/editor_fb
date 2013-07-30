#include "shape.h"

Shape::Shape(int x, int y, QString name):EditorMovingObject(x,y,name)
{
    penWidth=13.0;

    mode=0;//стандартный режим
    m_shape=QPainterPath();// очищаем путь, т.к. в конструкторе родительского класса он использовался

}

void Shape::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu * menu = new QMenu();
        QAction *removeAction = menu->addAction("Remove");
        QAction *resizeRectAction = menu->addAction("Resize Rect");
        QAction *selectedAction = menu->exec(event->screenPos());



        if(selectedAction==removeAction)
        {
            qDebug()<<"remove!!!!!!!";
            emit signal_itemDeleted(this);
        }

        if(selectedAction==resizeRectAction)
        {

            qDebug()<<type;
            if((type==OBJECT_TYPE_NOEDITSHAPE_RECT)
                    ||(type==OBJECT_TYPE_NOEDITSHAPE_ELLIPSE))
            {

                DialogAddShapeRect dlg;
                dlg.setup(pos().x(), pos().y(), width, height, name);
                dlg.show();
                if(dlg.exec() == QDialog::Accepted)
                    {
                        //запрашиваем параметры
                        int x=dlg.get_x();
                        int y=dlg.get_y();

                        int width=dlg.get_width();
                        int height=dlg.get_height();
                        QString name=dlg.get_name();


                        setName(name);
                        m_shape=QPainterPath();


                        if(type==OBJECT_TYPE_NOEDITSHAPE_RECT)
                        {
                            m_shape.addRect(0,0,width, height);

                        }
                        else if(type==OBJECT_TYPE_NOEDITSHAPE_ELLIPSE)
                        {
                            m_shape.addEllipse(0,0,width, height);
                        }
                        setPos(x,y);
                        this->width=width;
                        this->height=height;
                    }
            }
            //mode=1;

        }

        delete menu;
}




void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (mode==1)
    {
        int x=pos().x();
        int y=pos().y();
        m_shape=QPainterPath();

        m_shape.addRect(0,0, QCursor::pos().x(), QCursor::pos().y());

        setPos(x,y);
        boundingRect();
    }
}

void Shape::paint(QPainter *painter,
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

QPen pen;
pen.setWidth(penWidth);
painter->setPen(pen);
painter->drawPath(m_shape);//сформированный контур объекта


//painter->drawRect(boundingRect());

painter->drawText(m_shape.boundingRect(), name);//имя объекта
}
