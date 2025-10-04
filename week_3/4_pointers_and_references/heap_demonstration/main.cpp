#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

class Circle {
private:
    double diameter;
public:
    Circle(double d) : diameter(d) {}

    double getArea() {
        double r = diameter / 2;
        return pow(r, 2) * M_PI;
    }
};

class Cylinder : public Circle {
private:
    double depth;

public:
    Cylinder(double dia, double d) : Circle(dia), depth(d) {}

    double getVolume() {
        return getArea() * depth;
    }
};

void createCircle() {
    Circle* circle = new Circle(6);
}

int main(void) {

    Circle* circle1 = new Circle(3);
    Cylinder* cylinder1 = new Cylinder(3, 2);
    Circle* circle2 = new Circle(4);
    Cylinder* cylinder2 = new Cylinder(4, 3);

    delete circle2;

    Cylinder* cylinder3 = new Cylinder(5,3);

    return 0;
}

