#include "../include/exercise2.h"

#include <iostream>
#include <string>

int countLetter(std::string stringToCount, char characterToCount) {
    int counter = 0;

    for (auto c : stringToCount) {
        if (c == characterToCount) counter++;
    }

    return counter;
}

void runExercise2() {
    std::string userInput;
    char character;

    std::cout << "Enter string: ";
    std::getline(std::cin, userInput);

    std::cout << "Enter one character to count in the string: ";
    std::cin >> character;

    std::cout << "In the string \"" << userInput 
              << "\" the character '" << character
              << "' was found " << countLetter(userInput, character)
              << " times!" << std::endl;
}