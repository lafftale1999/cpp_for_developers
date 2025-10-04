#ifndef ANOTHER_CIRCLE_H_
#define ANOTHER_CIRCLE_H_

#define _USE_MATH_DEFINES

#include <cmath>

#include "./Shape.h"

class Circle : public Shape {
private:
    double diameter;

public:
    Circle(double d);

    double getDiameter() const;
    void setDiameter(double d);

    void printArea() const override;
    void printCircumference() const override;
};

#endif