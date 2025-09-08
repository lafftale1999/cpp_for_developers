#include <iostream>

int main(void) {

    struct Student {
        char firstName[20];
        char lastName[20];
        short int age;
        char grade;
    };

    Student student;

    snprintf(student.firstName, sizeof(student.firstName), "Ada");
    snprintf(student.lastName, sizeof(student.lastName), "Lovelace");
    student.age = 25;
    student.grade = 'A';
    
    return 0;
}