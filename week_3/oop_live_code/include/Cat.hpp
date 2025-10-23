#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal {
private:
    int jumpHeight;

public:
    Cat() = default;
    Cat(std::string n, std::string s, int a, int jh);
    void toString();
    void makeSound();
};

#endif