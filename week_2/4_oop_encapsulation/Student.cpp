#include "Student.h"

// DEFINITIONS

// STATIC VARIABLE INITIALIZATION
int Student::studentCounter = 0;

// CONSTRUCTOR
Student::Student(std::string name, std::string course, int age, char grade) {
    setName(name);
    setCourse(course);
    setAge(age);
    setGrade(grade);
    studentCounter++;
}

// DESTRUCTOR
Student::~Student() {
    studentCounter--;
}

// SHALLOW COPY
Student::Student(const Student& other)
: Student(other.name, other.course, other.age, other.grade) {
    std::cout << "Copy constructor called" << std::endl;
}

// DEEP COPY
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        name   = other.name;
        course = other.course;
        age    = other.age;
        grade  = other.grade;
    }
    return *this;
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
    return (
    s1.name == s2.name &&
    s1.course == s2.course &&
    s1.age == s2.age &&
    s1.grade == s2.grade
    );
}

bool operator<(const Student& s1, const Student& s2) {
    if (s1.age != s2.age) return s1.age < s2.age;
    if (s1.grade != s2.grade) return s1.grade < s2.grade;
    if (s1.name != s2.name) return s1.name < s2.name;
    return s1.course < s2.course;
}

// GETTERS
const std::string& Student::getName() {
    return this->name;
}

const std::string& Student::getCourse() {
    return this->course;
}

int& Student::getAge() {
    return this->age;
}

char Student::getGrade() {
    return this->grade;
}

// SETTERS
void Student::setName(const std::string& name) {
    int nameLength = name.length();

    if (name.empty() ||
        nameLength < STUDENT_NAME_MIN_LENGTH ||
        nameLength > STUDENT_NAME_MAX_LENGTH) {
        throw std::invalid_argument("Invalid student name!");
    }

    this->name = name;
}

void Student::setCourse(const std::string& course) {
    int courseNameLength = course.length();

    if (course.empty() ||
        courseNameLength < COURSE_NAME_MIN_LENGTH ||
        courseNameLength > COURSE_NAME_MAX_LENGTH) {
        throw std::invalid_argument("Invalid course name!");
    }

    this->course = course;
}

void Student::setAge(const int& age) {
    if (age < STUDENT_MIN_AGE || age > STUDENT_MAX_AGE) {
        throw std::invalid_argument("Invalid student age");
    }

    this->age = age;
}

void Student::setGrade(const char& grade) {
    if (grade < STUDENT_MAX_GRADE || grade > STUDENT_MIN_GRADE) {
        this->grade = 'F';
    } else {
        this->grade = grade;
    }
}