#include "../include/exercise1.h"

#include <iostream>

int addTwoNumbers(int x, int y) {
    return x + y;
}

void runExercise1() {
    int firstInput, secondInput;

    std::cout << "Enter the first number: ";
    std::cin >> firstInput;

    std::cout << "Enter the second number: ";
    std::cin >> secondInput;

    std::cout << firstInput << " + " << secondInput << " = " << addTwoNumbers(firstInput, secondInput) << std::endl;
}