#ifndef OWNER_HPP_
#define OWNER_HPP_

#include <iostream>
#include "Animal.hpp"

class Owner {
private:
    std::string name;
    std::string phoneNumber;
    Animal animal;
    const int memberId;

public:
    Owner(std::string n, std::string pn, Animal a, const int id);
};

#endif