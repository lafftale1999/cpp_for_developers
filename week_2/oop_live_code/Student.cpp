#include "Student.h"

int Student::studentCounter = 0;

Student::Student() {
    throw std::invalid_argument("Need to create a valid student");
}

Student::Student(std::string name, std::string address, char grade) {
    if (name.empty() || address.empty() || grade < 'A' || grade > 'F') {
        throw std::invalid_argument("Invalid");
    }
    
    setName(name);
    setAddress(address);
    setGrade(grade);
    studentCounter++;
}

Student::~Student() {
    studentCounter--;
}

void Student::setName(std::string name) {
    if (name.empty()) {
        throw std::invalid_argument("Name can't be empty!");
    }

    this->name = name;
}


void Student::setAddress(std::string address) {
    if (address.empty()) {
        throw std::invalid_argument("Address can't be empty");
    }

    this->address = address;
}


void Student::setGrade(char grade) {
    if (grade < 'A' && grade > 'F') {
        throw std::invalid_argument("Must be a valid grade between A-F");
    }

    this->grade = grade;
}

std::string Student::getName() {
    return name;
}

std::string Student::getAddress() {
    return address;
}

char Student::getGrade() {
    return grade;
}