#include "../include/dog.h"

Dog::Dog() {
    name = "";
    sound = "";
    age = 0;
}

Dog::Dog(std::string n, std::string s, int a) {
    name = n;
    sound = s;
    age = a;
}