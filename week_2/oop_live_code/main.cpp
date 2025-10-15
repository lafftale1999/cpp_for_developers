#include <iostream>
#include "Student.h"

int main(void) {

    Student s1 = Student("Carl", "Carlway 22", 'C');

    std::cout << s1.getName() << " lives on " << s1.getAddress() << std::endl;

    s1.setAddress("New Carlway 2202");

    std::cout << s1.getName() << " lives on " << s1.getAddress() << std::endl;

    return 0;
}