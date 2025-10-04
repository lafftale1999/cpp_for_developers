#ifndef ANOTHER_2D_SHAPE_H_
#define ANOTHER_2D_SHAPE_H_

#include <iostream>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void printArea() const = 0;
    virtual void printCircumference() const = 0;
};

#endif

