#include "../include/Student.h"

Student::Student(int age, std::string name, char grade, const Course& course) 
    : age(0), name(), grade('F'), course(course)
{
    this->setAge(age);
    this->setName(name);
    this->setGrade(grade);
}
    
void Student::setAge(int age) {
    if (age < 18) {
        throw std::invalid_argument("Student ineligeble for this education");
    } 

    this->age = age;
}

void Student::setName(std::string name) {
    if (name.empty()) {
        throw std::invalid_argument("A name must be entered");
    }

    this->name = name;
}

void Student::setGrade(char grade) {
    if (grade > 'F' || grade < 'A') {
        throw std::invalid_argument("Grade is not eligble");
    }

    this->grade = grade;
}

void Student::setCourse(Course course) {
    this->course = course;
}

int Student::getAge() {
    return this->age;
}

std::string Student::getName() {
    return this->name;
}

char Student::getGrade() {
    return this->grade;
}

Course Student::getCourse() {
    return this->course;
}