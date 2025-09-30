#include "../include/Shape3D.h"

Shape3D::Shape3D(double l, double w, double d) 
: Shape2D(l, w), depth(d) {
    if (depth <= 0) {
        throw std::invalid_argument("Depth must be bigger than 0");
    }
}

void Shape3D::setDepth(double d) {
    if (d <= 0) {
        throw std::invalid_argument("Depth must be bigger than 0");
    }

    depth = d;
}
    
double Shape3D::getDepth() {
    return depth;
}

double Shape3D::getVolume() {
    return getLength() * getWidth() * depth;
}

void Shape3D::printShape() {
    std::cout << "I'm a 3D shape" << std::endl;
}