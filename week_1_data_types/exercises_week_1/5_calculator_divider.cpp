#include <iostream>

/* 
    Write an application that takes the user input for two numbers and then divide them.
*/

int main(void) {

    float number1 = 0;
    float number2 = 0;

    std::cout << "Welcome to the divider. Enter 2 numbers that will be divided" << std::endl;
    std::cout << "First number: ";
    std::cin >> number1;
    std::cout << "Second number: ";
    std::cin >> number2;

    std::cout << number1 << " / " << number2 << " = " << number1 / number2 << std::endl;

    return 0;
}