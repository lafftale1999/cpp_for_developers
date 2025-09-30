#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "Shape3D.h"

class Cylinder : public Shape3D {
public:
    Cylinder(double w, double d);

    double getCircumference() override;
    double getArea() override;
    double getVolume() override;
    void printShape() override;
};

#endif