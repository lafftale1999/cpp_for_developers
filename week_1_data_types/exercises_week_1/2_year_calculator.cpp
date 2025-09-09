#include <iostream>

/* 
    Create an application that takes the users 
*/
int main(void) {

    int currentYear = 2025;
    int userBirthYear = 0;
    int userAge = 0;

    std::cout << "Enter which year you where born: ";
    std::cin >> userBirthYear;

    userAge = currentYear - userBirthYear;

    std::cout << "You are " << userAge << " years old!" << std::endl;

    return 0;
}