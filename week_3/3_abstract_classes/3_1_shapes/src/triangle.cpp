#include "../include/triangle.h"

Triangle::Triangle(double h, double w)
: height(h), aLen(0), base(w), cLen(0) {
    if (height <= 0 ||
        base <= 0) {
            throw std::invalid_argument("Unable to create Triangle");
        }
}

Triangle::Triangle(double h, double a, double b, double c)
: height(h), aLen(a), base(b), cLen(c) {
    if (height <= 0 ||
        aLen <= 0 ||
        base <= 0 ||
        cLen <= 0) {
            throw std::invalid_argument("Unable to initialize Triangle");
        }
}

double Triangle::getHeight() const {
    return height;
}

double Triangle::getBase() const {
    return base;
}

void Triangle::setHeight(double h) {
    if (h <= 0) {
        throw std::invalid_argument("Height can't be <= 0");
    }

    height = h;
}

void Triangle::setWidth(double b) {
    if (b <= 0) {
        throw std::invalid_argument("Width can't be <= 0");
    }

    base = b;
}

void Triangle::printArea() const {
    double area = (base * height) / 2;
    std::cout << "Triangle area: " << area << std::endl;
}

void Triangle::printCircumference() const {
    if (aLen && base && cLen) {
        double c = aLen + base + cLen;
        std::cout << "Triangle circumference: " << c << std::endl;
    } else {
        std::cout << "Triangle circumference: Undefineable - need more information\n";
    }
}