#include "include/AllShapes.h"

#include <vector>

int main(void) {
    Shape shape = Shape(10);
    Shape2D shape2d = Shape2D(10, 10);
    Shape3D shape3d = Shape3D(10, 10, 10);

    Square square = Square(10, 10);
    Circle circle = Circle(10);

    Cylinder cylinder = Cylinder(10, 10);
    Cube cube = Cube(10, 10, 10);

    std::cout << "---------------------- ALL SHAPES ---------------------------" << std::endl;
    std::vector<Shape*> shapes = {&shape, &shape2d, &shape3d, &square, &circle, &cylinder, &cube};
    for (const auto& s : shapes) {
        s->printShape();
    }

    std::cout << "---------------------- TWO DIMENSIONAL SHAPES ---------------------------" << std::endl;
    std::vector<Shape2D*> shapes2d = {&shape2d, &square, &circle};
    for (const auto& s : shapes2d) {
        std::cout << "Area: " << s->getArea() << " \t\t Circumference: " << s->getCircumference() << std::endl; 
    }

    std::cout << "---------------------- THREE DIMENSIONAL SHAPES ---------------------------" << std::endl;
    std::vector<Shape3D*> shapes3d = {&shape3d, &cube, &cylinder};
    for (const auto& s : shapes3d) {
        std::cout << "Area: " << s->getArea() << " \t\t Circumference: " << s->getCircumference() << " \t Volume: " << s->getVolume() << std::endl;
    }
    
    return 0;
}