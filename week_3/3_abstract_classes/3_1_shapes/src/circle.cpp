#include "../include/circle.h"

Circle::Circle(double d) 
: diameter(d) {
    if (diameter <= 0) {
        throw std::invalid_argument("Diameter can't be <= 0");
    }
}

double Circle::getDiameter() {
    return diameter;
}

void Circle::setDiameter(double d) {
    if (d <= 0) {
        throw std::invalid_argument("Diameter can't be <= 0");
    }

    diameter = d;
}

void Circle::printArea() const {
    double area = pow((diameter / 2), 2) * M_PI;
    std::cout << "Circle area: " << area << std::endl;
}

void Circle::printCircumference() const {
    double circumference = diameter * M_PI;
    std::cout << "Circle circumference: " << circumference << std::endl;
}