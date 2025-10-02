#ifndef _CAT_H_
#define _CAT_H_

#include "animal.h"

class Cat : public Animal {
private:
    double jumpHeight;

public:
    Cat(std::string n, std::string s, int a, double jh);

    void jump();
};

#endif