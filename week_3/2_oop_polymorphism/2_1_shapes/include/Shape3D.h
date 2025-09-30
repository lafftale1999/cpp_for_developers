#ifndef SHAPE_3D_H_
#define SHAPE_3D_H_

#include "Shape2D.h"

class Shape3D : public Shape2D {
private:
    double depth;

public:
    Shape3D(double l, double w, double d);

    void setDepth(double d);
    double getDepth();

    virtual double getVolume();
    void printShape() override;
};

#endif