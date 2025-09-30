#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape2D.h"

class Circle : public Shape2D {
public:
    Circle(double w);
    double getCircumference() override;
    double getArea() override;
    void printShape() override;
};

#endif