#ifndef ANOTHER_SQUARE_H_
#define ANOTHER_SQUARE_H_

#include <iostream>

#include "./Shape.h"

class Square : public Shape {
private:
    double width;
    double height;

public:
    Square(double w, double h);

    void setWidth(double w);
    void setHeight(double h);

    double getWidth() const;
    double getHeight() const;

    void printArea() const override;
    void printCircumference() const override;
};

#endif