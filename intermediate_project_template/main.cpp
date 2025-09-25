#include <iostream>
#include <vector>

#include "include/Student.h"

int main(void) {

    std::vector<Student> students;
    Course course = Course("C++ for Developers", 2, 40);
    students.push_back(Student(29, "Carl", 'F', course));
    students.push_back(Student(35, "Ali", 'B', course));
    students.push_back(Student(28, "Sami", 'C', course));
    students.push_back(Student(42, "Johanna", 'A', course));

    std::cout << "Course: \"" << course.getCourseName() << "\"" << std::endl;
    std::cout << "Course length: " << course.getLengthInMonths() << " months" << std::endl;
    std::cout << "YH-points: " << course.getPoints() << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Students enrolled:" << std::endl;
    
    for(auto student : students) {
        std::cout << "Name: " << student.getName() << " | Age: " << student.getAge() << " | Grade: " << student.getGrade() << std::endl;
    }

    return 0;
}