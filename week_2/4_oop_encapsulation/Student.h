#ifndef OOP_INTRO_STUDENT_CLASS_H
#define OOP_INTRO_STUDENT_CLASS_H

#include <iostream>

#define STUDENT_MIN_AGE 18
#define STUDENT_MAX_AGE 65
#define STUDENT_NAME_MIN_LENGTH 3
#define STUDENT_NAME_MAX_LENGTH 50
#define COURSE_NAME_MIN_LENGTH 3
#define COURSE_NAME_MAX_LENGTH 30
#define STUDENT_MIN_GRADE 'F'
#define STUDENT_MAX_GRADE 'A'

class Student {
private:
    std::string name;
    std::string course;
    int age;
    char grade;

    static int studentCounter;

public:
    Student(std::string name, std::string course, int age, char grade);
    ~Student();

    static void printStudentCounter();
    void printStudentInformation();

    friend bool operator==(const Student& s1, const Student& s2);
    friend bool operator<(const Student& s1, const Student& s2);

    // GETTERS
    const std::string& getName();
    const std::string& getCourse();
    int& getAge();
    char getGrade();

    // SETTERS
    void setName(const std::string& name);
    void setCourse(const std::string& course);
    void setAge(const int& age);
    void setGrade(const char& grade);
};

#endif