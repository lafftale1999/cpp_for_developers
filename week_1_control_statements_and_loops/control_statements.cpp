#include <iostream>

int main(void) {

    /* 
    Comparison operators         Example:
    == is equal                  x == y
    != is not equal              x != y
    < is less than               x < y
    > is greater than            x > y
    <= less than or equal        x <= y
    >= greater than or equal     x >= y

    Logical operators            Example:            Explanation:
    && and                       x == y && y < z     both of these must be true
    || or                        x == y || y < z     one of these must be true
    ! not                        !(x == y)           reverse the result

    IF / IF ELSE / ELSE
    'if' is always the first statement.
    if not true, the program will check the 'else if' statements. You can
    chain as many 'else if' statements after an 'if' that you need.
    'else' works as a default, if none of the statements are true, the
    code in the 'else' statement will execute.
    */
    
    bool thisIsTrue = true;
    bool thisIsFalse = false;

    // IF THE 'IF' STATEMENT IS TRUE
    if (thisIsTrue) {
        std::cout << "If is true" << std::endl;
    } else if (thisIsFalse) {
        std::cout << "Else if is true" << std::endl;
    } else {
        std::cout << "Neither was true" << std::endl;
    }


    // IF THE 'ELSE IF' STATEMENT IS TRUE
    if (thisIsFalse) {
        std::cout << "If is true" << std::endl;
    } else if (thisIsTrue) {
        std::cout << "Else if is true" << std::endl;
    } else {
        std::cout << "Neither was true" << std::endl;
    }


    // IF NONE IS TRUE
    if (thisIsFalse) {
        std::cout << "If is true" << std::endl;
    } else if (thisIsFalse) {
        std::cout << "Else if is true" << std::endl;
    } else {
        std::cout << "Neither was true" << std::endl;
    }


    // CHAINING 'ELSE IF' STATEMENTS
    // remember that the program will execute descending
    if (thisIsFalse) {
        std::cout << "If is true" << std::endl;
    } else if (thisIsFalse) {
        std::cout << "first else if is true" << std::endl;
    } else if (thisIsFalse) {
        std::cout << "second else if is true" << std::endl;
    } else if (thisIsTrue) {
        std::cout << "third else if is true" << std::endl;
    } else {
        std::cout << "Neither was true" << std::endl;
    }


    // USING LOGICAL OPERATORS
    char scholarschipGradeMinimum = 'A';
    int minimumAge = 18;

    struct Student {
        char grade;
        int age;
        std::string name;
    };

    Student student1 = {
        'C',
        23,
        "Hubert"
    };

    Student student2 = {
        'A',
        18,
        "Bluebert"
    };

    if (student1.age >= 18 && student1.grade == scholarschipGradeMinimum) {
        std::cout << student1.name + " has received a scholarschip!" << std::endl;
    } else if (student2.age >= 18 && student2.grade == scholarschipGradeMinimum) {
        std::cout << student2.name + " has received a scholarschip!" << std::endl;
    } else {
        std::cout << "No one received the scholarship!" << std::endl;
    }

    return 0;
}