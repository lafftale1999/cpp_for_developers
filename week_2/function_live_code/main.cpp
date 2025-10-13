#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <string>

#include "exercise1.h"

int main(void) {

    exercise1main();

    /* std::ofstream tofile("example.txt", std::ios::app);

    if (!tofile.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    tofile << "Another line of text" << std::endl;

    tofile.close();

    std::ifstream file("example.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    std::string tempString;

    while(std::getline(file, tempString)) {
        std::cout << tempString << std::endl;
    }

    file.close();
 */
    /* const int cInt = 0;

    std::vector<int> values = {9, 8, 3, 22};

    int userInput = 0;

    while (userInput != -1) {
        try {
            std::cout << "enter the index for vector: ";
            std::cin >> userInput;
            
            if ((size_t)userInput >= values.size()) {
                throw std::out_of_range("Our own exception thrown");
            }

            std::cout << values.at(userInput) << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    } */
    
    return 0;
}