#include "Student.h"

// DEFINITIONS

// STATIC VARIABLE INITIALIZATION
int Student::studentCounter = 0;

// CONSTRUCTOR
Student::Student(std::string name, std::string course, int age, char grade) {
    this->name = name;
    this->course = course;
    this->age = age;
    this->grade = grade;
    studentCounter++;
}

// DESTRUCTOR
Student::~Student() {
    studentCounter--;
}

// STATIC METHOD
void Student::printStudentCounter() {
    std::cout << "Current amount of students: " << studentCounter << std::endl;
}

// METHOD
void Student::printStudentInformation() {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Student: " << name << std::endl;
    std::cout << "Course: " << course << std::endl;
    std::cout << "Age: " << age << " years old" << std::endl;
    std::cout << "Grade: " << grade << std::endl;
}

// COMPARISON OPERATOR OVERLOAD
bool operator==(const Student& s1, const Student& s2) {
    return s1.age == s2.age;
}

bool operator<(const Student& s1, const Student& s2) {
    return s1.age < s2.age;
}