#ifndef SHAPE_H
#define SHAPE_H
#include "editormovingobject.h"
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include <QColor>

#include "dialogaddshaperect.h"



class Shape: public EditorMovingObject
{

public:
   Shape(int x, int y, QString name);

   virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);




   virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

   virtual void paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget);// метод отрисовки



    //virtual QRectF boundingRect();

protected:
   int mode;

   float penWidth;

   QColor penColor;



};

#endif // SHAPE_H
