#include <iostream>
#include <vector>

#include "include/square.h"
#include "include/triangle.h"
#include "include/circle.h"

void printCircleInformation(const Circle& circle) {
    circle.printArea();
    circle.printCircumference();
}

int main(void) {
    Circle circle = Circle(10);
    Triangle triangle = Triangle(10,10);
    Square square = Square(10, 10);

    std::vector<Shape*> shapes = {&circle, &triangle, &square};

    for (const auto& s : shapes) {
        s->printArea();
        s->printCircumference();
    }
}