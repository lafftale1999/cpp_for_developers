#ifndef CUBE_H_
#define CUBE_H_

#include "Shape3D.h"

class Cube : public Shape3D {
public:
    using Shape3D::Shape3D;
    void printShape() override;
};

#endif