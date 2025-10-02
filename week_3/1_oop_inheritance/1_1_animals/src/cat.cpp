#include "../include/cat.h"

Cat::Cat(std::string n, std::string s, int a, double jh) 
: Animal(n, s, a), jumpHeight(jh) {}

void Cat::jump() {
    std::cout << getName() << " jumped " << jumpHeight << "cm into the air!" << std::endl;
}