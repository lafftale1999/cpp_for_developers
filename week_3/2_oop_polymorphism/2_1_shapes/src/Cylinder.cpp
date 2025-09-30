#include "../include/Cylinder.h"

Cylinder::Cylinder(double w, double d)
: Shape3D(1, w, d){

}

double Cylinder::getCircumference() {
    return getWidth() * M_PI;
}

double Cylinder::getArea() {
    return std::pow((getWidth() / 2), 2) * M_PI;
}

double Cylinder::getVolume() {
    return getArea() * getDepth();
}

void Cylinder::printShape() {
    std::cout << "I'm a cylinder!" << std::endl;
}