#include "../include/square.h"

Square::Square(double w, double h)
: width(w), height(h){
    if (width <= 0 ||
        height <= 0 ||
        width != height) {
            throw std::invalid_argument("Unable to create Square");
        }
}

void Square::setWidth(double w) {
    if (w <= 0) {
        throw std::invalid_argument("Width can't be <= 0");
    }

    width = w;
}

void Square::setHeight(double h) {
    if (h <= 0) {
        throw std::invalid_argument("Height can't be <= 0");
    }

    height = h;
}

double Square::getWidth() const {
    return width;
}

double Square::getHeight() const {
    return height;
}

void Square::printArea() const {
    double area = height * width;
    std::cout << "Square area: " << area << std::endl;
}

void Square::printCircumference() const {
    double area = (height * 2) + (width * 2);
    std::cout << "Square circumference: " << area << std::endl;
}