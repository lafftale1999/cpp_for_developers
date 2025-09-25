#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include <iostream>
#include "Course.h"

class Student {

private:
    int age;
    std::string name;
    char grade;
    Course course;

public:
    Student(int age, std::string name, char grade, const Course& course);
    
    void setAge(int age);
    void setName(std::string name);
    void setGrade(char grade);
    void setCourse(Course course);

    int getAge();
    std::string getName();
    char getGrade();
    Course getCourse();
};

#endif