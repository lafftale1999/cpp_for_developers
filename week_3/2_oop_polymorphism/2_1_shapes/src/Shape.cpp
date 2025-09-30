#include "../include/Shape.h"

Shape::Shape(double l)
: length(l){
    if (length <= 0) {
            throw std::invalid_argument("Length must be bigger than 0");
        }
}

void Shape::setLength(double l) {
    if (l <= 0) {
        throw std::invalid_argument("Length must be bigger than 0");
    }

    length = l;
}

double Shape::getLength() {
    return length;
}

void Shape::printShape() {
    std::cout << "I'm a Shape" << std::endl;
}