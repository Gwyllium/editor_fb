#ifndef SHAPERECT_H
#define SHAPERECT_H

#include "shape.h"


class noEditShape : public Shape
{
public:
    noEditShape(int type, int x, int y, int width, int height, QString name);

    void set_size(int w, int h);




};

#endif // SHAPERECT_H
