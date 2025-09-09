#include <iostream>

/* 
    Create a program that will take a number in minutes (minimum 60 minutes) and converts it into
    hours and minutes.
*/

int main(void) {

    int userInputMinutes = 0;
    int outputHours = 0;
    int outputMinutes = 0;

    std::cout << "Enter how many minutes you want to calculate! Minimum 60 minutes: ";
    std::cin >> userInputMinutes;

    outputHours = userInputMinutes / 60;
    outputMinutes = userInputMinutes - (outputHours * 60);

    std::cout << "Hours: " << outputHours << std::endl;
    std::cout << "Minutes: " << outputMinutes << std::endl;

    return 0;
}