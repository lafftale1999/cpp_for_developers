#include <iostream>
#include <vector>

#include "Student.h"

int main(void) {
    // STACK ALLOCATION
    Student student1 = Student("Mommo Sadeghi", "C++ for Developers", 23, 'A');
    Student student2 = Student("Maja Wójcik", "C++ for Developers", 27, 'A');

    student1.printStudentInformation();
    student2.printStudentInformation();

    // HEAP ALLOCATION
    Student* studentOnHeap = new Student("Ronja Voxx", "C++ for developers", 34, 'A');
    Student* anotherStudentOnHeap = studentOnHeap;

    studentOnHeap->name = "Ami Moreau";
    anotherStudentOnHeap->printStudentInformation();
    delete studentOnHeap;

    std::string name;

    return 0;
}