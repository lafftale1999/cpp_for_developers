#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>

class Student {
private:
    std::string name;
    std::string address;
    char grade;

    static int studentCounter;

public:
    Student();
    Student(std::string name, std::string address, char grade);

    ~Student();
    
    void setName(std::string name);
    void setAddress(std::string address);
    void setGrade(char grade);

    std::string getName();
    std::string getAddress();
    char getGrade();
};

#endif