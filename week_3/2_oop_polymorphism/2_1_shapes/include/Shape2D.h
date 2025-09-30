#ifndef _2D_SHAPE_H_
#define _2D_SHAPE_H_

#include "shape.h"

class Shape2D : public Shape {
private:
    double width;

public:
    Shape2D(double l, double w);

    void setWidth(double w);
    double getWidth();

    virtual double getCircumference();
    virtual double getArea();

    void printShape() override;
};

#endif