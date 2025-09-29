#include "../include/Course.h"

Course::Course(std::string courseName, int lengthInMonths, int points)
: courseName("Not initialized"), lengthInMonths(1), points(1) 
{
    this->setCourseName(courseName);
    this->setLengthInMonths(lengthInMonths);
    this->setPoints(points);
}

void Course::setCourseName(std::string courseName) {
    if (courseName.empty()) {
        throw std::invalid_argument("Course name must be entered");
    }

    this->courseName = courseName;
}

void Course::setLengthInMonths(int lengthInMonths) {
    if (lengthInMonths <= 0) {
        throw std::invalid_argument("The course must be 1 month or longer");
    }

    this->lengthInMonths = lengthInMonths;
}

void Course::setPoints(int points) {
    if (points <= 0) {
        throw std::invalid_argument("Course must award more than 1 point");
    }

    this->points = points;
}

std::string Course::getCourseName() {
    return this->courseName;
}
    
int Course::getLengthInMonths() {
    return this->lengthInMonths;
}

int Course::getPoints() {
    return this->points;
}