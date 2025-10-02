#ifndef _OWNER_H_
#define _OWNER_H_

#include "animal.h"

class Owner {
private:
    std::string name;
    std::string phone;
    Animal animal;

public:
    Owner(std::string n, std::string p, Animal a);
};

#endif