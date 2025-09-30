#include "../include/Shape2D.h"

Shape2D::Shape2D(double l, double w)
: Shape(l), width(w) {
    if (width <= 0) {
        throw std::invalid_argument("Width must be bigger than 0");
    }
}

void Shape2D::setWidth(double w) {
    if (w <= 0) {
        throw std::invalid_argument("Width must be bigger than 0");
    }

    width = w;
}
    
double Shape2D::getWidth() {
    return width;
}

double Shape2D::getCircumference() {
    return (getLength() * 2) + (width * 2);
}

double Shape2D::getArea() {
    return getLength() * width;
}

void Shape2D::printShape() {
    std::cout << "I'm a 2 dimensional shape" << std::endl;
}