#ifndef _DOG_H_
#define _DOG_H_

#include "animal.h"

class Dog {
private:
    std::string name;
    std::string sound;
    int age;

public:
    Dog();
    Dog(std::string n, std::string s, int a);
    
};

#endif