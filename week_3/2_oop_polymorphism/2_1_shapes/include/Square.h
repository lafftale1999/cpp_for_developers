#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape2D.h"

class Square : public Shape2D {
public:
    using Shape2D::Shape2D;
    void printShape() override;
};

#endif