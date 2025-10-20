#include "../include/Animal.hpp"

Animal::Animal(std::string n, std::string s, int a) {
    name = n;
    sound = s;
    age = a;
}

void Animal::makeSound() {
    std::cout << "The " << name << " said " << sound << std::endl;
}

void Animal::setName(std::string n) {
    name = n;
}

void Animal::setSound(std::string s) {
    sound = s;
}

void Animal::setAge(int a) {
    age = a;
}

std::string Animal::getName() {
    return name;
}

std::string Animal::getSound() {
    return sound;
}

int Animal::getAge() const {
    return age;
}