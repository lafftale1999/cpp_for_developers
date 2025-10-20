#include "../include/Cat.hpp"

Cat::Cat(std::string n, std::string s, int a, int jh)
: Animal(n,s,a), jumpHeight(jh) {};

void Cat::toString() {
    std::cout << getName() << " | " << getSound() << " | " << getAge() << std::endl;
}

void Cat::makeSound() {
    std::cout << getName() << " said meow\n";
}