// The standard library for I/O operations
#include <iostream>

// Entry point to the program
int main(void) {

    // Program functionality
    std::string name = "Carl Broman";
    int age = 32;

    std::cout << name << " is " << age << " years old" << std::endl;

    // Returning 0 - 0 often indicates that nothing went wrong (everything went well)
    return 0;
}