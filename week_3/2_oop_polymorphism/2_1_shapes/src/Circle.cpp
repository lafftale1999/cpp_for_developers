#include "../include/Circle.h"

Circle::Circle(double w) 
: Shape2D(1, w) {}

double Circle::getCircumference() {
    return getWidth() * M_PI;
}

double Circle::getArea() {
    return std::pow((getWidth() / 2), 2) * M_PI;
}

void Circle::printShape() {
    std::cout << "I'm a circle!" << std::endl;
}