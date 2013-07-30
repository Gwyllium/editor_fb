#ifndef EDITORMOVINGOBJECT_H
#define EDITORMOVINGOBJECT_H

#define OBJECT_TYPE_NOEDITSHAPE_RECT 101
#define OBJECT_TYPE_NOEDITSHAPE_ELLIPSE 102

#define OBJECT_TYPE_EDITSHAPE 111




#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStyleOptionGraphicsItem>


#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QList>
#include <QPoint>
#include <QCursor>
#include <QObject>
#include <QPainter>


#include <QDir>


class EditorMovingObject : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    explicit EditorMovingObject(int x, int y, QString name,QObject *parent = 0, QGraphicsItem *item=0);

    virtual void paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget);// метод отрисовки

        QPainterPath m_shape;

        virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
           virtual QRectF boundingRect() const;// определяет границы перерисовки

        void setName(QString name);



protected:
            int type;

            int width;
            int height;


public:

             QString name;
signals:

        void signal_itemChanged(EditorMovingObject *obj, int type);

        void signal_itemDeleted(EditorMovingObject *obj);

        void signal_itemSelected(EditorMovingObject *obj);
    
public slots:
    void slot_itemPosChanged(EditorMovingObject *obj, int x, int y);
    void slot_itemNameChanged(EditorMovingObject *obj, QString name);
    
};

#endif // EDITORMOVINGOBJECT_H
