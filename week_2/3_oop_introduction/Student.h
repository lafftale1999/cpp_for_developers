#ifndef OOP_INTRO_STUDENT_CLASS_H
#define OOP_INTRO_STUDENT_CLASS_H

#include <iostream>

// DECLARATION
class Student {

// Access modifier
public:
    // Attributes
    std::string name;
    std::string course;
    int age;
    char grade;

    // Static attribute
    static int studentCounter;

    // Constructor
    Student(std::string name, std::string course, int age, char grade);
    
    // Destructor
    ~Student();

    // Static method
    static void printStudentCounter();

    // Method
    void printStudentInformation();

    // OVERLOADING COMPARISON OPERATOR
    friend bool operator==(const Student& s1, const Student& s2);
    friend bool operator<(const Student& s1, const Student& s2);
};

#endif