#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

int main(void) {

    // An exception is thrown when something against the c++ rules happens
    // for example trying to access an element outside a std::vector

    std::vector<int> values = {3, 9, 11, 12};
    std::cout << values.at(4) << std::endl; // <- this will cause an out of range exception

    // To avoid crashing the program when errors occur, we can try to handle them
    // by creating try-catch statements

    try { // start with the try body - this is where you put the code that might throw an exception
        std::cout << values.at(4) << std::endl;
    } catch (const std::exception& e) { // we "catch" the exception as a const reference and assign it the name 'e'.
        std::cout << e.what() << std::endl;
    }

    // We are also able to create loops with try catch that can handle userInput in a better way
    // by prompting them with entering a valid answer:
    int userInput = 0;
    std::string prompt = "Enter a number between 0 and " + std::to_string(values.size()) + " | or -1 to quit!\n";
    std::cout << prompt;

    while (userInput != -1) {
        try {
            
            std::cin >> userInput; // <- Received the user input

            if (std::cin.fail()) { // <- Check if it failed
                throw std::runtime_error("Wrong type entered!");
            }

            if (userInput == -1) break; // <- Check if the break condition is entered
            if ((size_t)userInput >= values.size() || userInput < 0) { // <- check if its in range
                throw std::out_of_range("Out of range");
            }

            // Perform the task
            std::cout << "Values(" << userInput << ") = " << values.at(userInput) << std::endl;

            // Define what happens when an exception is thrown
            // here we prompt the user, clears the input stream and restart the loop.
        } catch (const std::exception& e) {
            std::cout << prompt;
            std::cin.clear();
            continue; 
        }
    }

    return 0;
}