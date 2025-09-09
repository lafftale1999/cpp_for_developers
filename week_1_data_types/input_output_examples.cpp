#include <iostream>

int main(void) {
    // Dont mind the {}! they are used to separate the code to be able to showcase
    // the examples with the same names on the variables.

    {
        int age = 29;
        char name[] = "Carl Broman";

        std::cout << name << " is " << age << " years old." << std::endl;
    }

    {
        int age;
        char name[20];

        std::cout << "Whats your name?" << std::endl;
        std::cin >> name;
        
        std::cout << "How old are you?" << std::endl;
        std::cin >> age;
        
        std::cout << name << " is " << age << " years old." << std::endl;
    }

    return 0;
}