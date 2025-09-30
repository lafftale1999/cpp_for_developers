#ifndef SHAPE_H_
#define SHAPE_H_

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

class Shape {
private:
    double length;

public:
    Shape(double l);
    
    void setLength(double l);
    double getLength();

    virtual void printShape();
};

#endif