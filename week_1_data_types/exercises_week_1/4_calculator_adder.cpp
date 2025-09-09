#include <iostream>

/* 
    Write an application that takes the user input for two numbers and then adds them together.
*/

int maint(void) {

    int number1 = 0;
    int number2 = 0;

    std::cout << "Welcome to the adder. Enter 2 numbers that will be added together" << std::endl;
    std::cout << "First number: ";
    std::cin >> number1;
    std::cout << "Second number: ";
    std::cin >> number2;

    std::cout << number1 << " + " << number2 << " = " << number1 + number2 << std::endl;
}