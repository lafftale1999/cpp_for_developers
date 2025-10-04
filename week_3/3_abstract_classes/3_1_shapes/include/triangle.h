#ifndef ANOTHER_TRIANGLE_H_
#define ANOTHER_TRIANGLE_H_

#include "./Shape.h"

class Triangle : public Shape {
private:
    double height;
    double aLen;
    double base;
    double cLen;

public:
    Triangle(double h, double b);
    Triangle(double h, double a, double b, double c);
    
    double getHeight() const;
    double getBase() const;
    void setHeight(double h);
    void setWidth(double w);

    void printArea() const override;
    void printCircumference() const override;
};

#endif