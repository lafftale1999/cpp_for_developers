#include <iostream>

int main(void) {

    /* 
    SIMPLE EXCEPTION HANDLING
    ---
    By wrapping I/O operations in try/catch we can avoid crashing the program
    and instead handle the exceptions ourselves. 
    */
    std::string name;
    std::cout << "Enter your name: ";

    try {
        std::cin >> name;
        if (std::cin.fail() || name.empty() || name.length() < 5) {
            throw std::invalid_argument("You must enter a valid name (at least 5 characters)");
        }

        std::cout << "Hello " << name << "!" << std::endl;

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    /*
    FORCE CORRECT SCENARIO
    ---
    By wrapping our I/O operation in a loop with a try/catch we can prompt the user
    until it enters the input in a format we accept!
    */

    std::string email;
    
    while(true) {
        std::cout << "Enter your email: ";

        try {
            std::cin >> email;

            if (std::cin.fail()) {
                std::cin.clear();
                throw std::invalid_argument("You must enter something");
            }
            else if (email.empty() || email.length() < 6) {
                throw std::invalid_argument("Enter a valid email (must contain 6 or more characters)");
            }
            else if (email.find('@') == std::string::npos) {
                throw std::invalid_argument("Missing '@'. Enter a valid email");
            }

            std::cout << "Welcome " << email << "!" << std::endl;
            break;

        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}