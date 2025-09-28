#include <iostream>
#include <vector>

#include "Student.h"

int main(void) {
    
    Student student1 = Student("Mommo Sadeghi", "C++ for Developers", 23, 'A');
    Student student2 = Student("Maja Wójcik", "C++ for Developers", 27, 'A');

    student1.setName("Mohammed Sadeghi");
    std::cout << student1.getName() << std::endl;

    return 0;
}