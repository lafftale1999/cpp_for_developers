#include "../include/reference.hpp"

#include <iostream>
#include <vector>

struct Person {
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}
};

int referenceMain(void) {
    Person p("Carl", 29);

    Person& pReference = p;

    std::cout << pReference.name << " is " << pReference.age << " years old!\n";

    return 0;
}