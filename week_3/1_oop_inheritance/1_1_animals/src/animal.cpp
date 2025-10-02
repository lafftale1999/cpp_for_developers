#include "../include/animal.h"

/* Member-initializer list:
   Each member is directly constructed with the given value.
   If we instead assigned inside the body, the members would first
   be default-constructed and then reassigned, which can be wasteful
   (or even impossible for const, reference, or non-assignable types).
*/
Animal::Animal(std::string n, std::string s, int a) 
  : name(std::move(n)), sound(std::move(s)), age(a) // <- Member-initializer list
{}

void Animal::makeSound() {
    std::cout << name << " said " << sound << "!\n";
}

void Animal::run() {
    std::cout << name << " is running very fast!\n";
}

// ------------------ GETTERS AND SETTERS -----------------------------
void Animal::setName(std::string n) {
    if (n.empty()) {
        throw std::invalid_argument("Name can't be empty!");
    }

    name = n;
}

void Animal::setSound(std::string s) {
    if (s.empty()) {
        throw std::invalid_argument("Sound can't be empty!");
    }

    sound = s;
}

void Animal::setAge(int a) {
    if (age <= 0) {
        throw std::invalid_argument("Age must be older than 0");
    }

    age = a;
}

const std::string& Animal::getName() {
    return name;
}

const std::string& Animal::getSound() {
    return sound;
}

int Animal::getAge() {
    return age;
}

