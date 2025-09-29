#ifndef COURSE_CLASS_H
#define COURSE_CLASS_H

#include <iostream>

class Course {
private:
    std::string courseName;
    int lengthInMonths;
    int points;

public:
    Course(std::string courseName, int lengthInMonths, int points);
    Course();

    void setCourseName(std::string courseName);
    void setLengthInMonths(int lengthInMonths);
    void setPoints(int points);

    std::string getCourseName();
    int getLengthInMonths();
    int getPoints();
};

#endif