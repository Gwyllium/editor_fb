#include "noEditShape.h"

noEditShape::noEditShape(int type, int x, int y, int width, int height, QString name):Shape(x,y,name)
{
    this->width=width;
    this->height=height;

    switch(type)
    {

        case 1:
        m_shape.addRect(0,0,width,height);
        this->type=OBJECT_TYPE_NOEDITSHAPE_RECT;
        break;
        case 2:
        m_shape.addEllipse(0,0,width,height);
        this->type=OBJECT_TYPE_NOEDITSHAPE_ELLIPSE;
        break;
    }


    setPos(x,y);

}

void noEditShape::set_size(int w, int h)
{
    width=w;
    height=h;
}


