#ifndef CAR_H_
#define CAR_H_

#include <iostream>

class Bus {
private:
    std::string model;

public:
    Bus(std::string model);

    void honk();

    friend bool operator==(const Bus& b1, const Bus& b2);
};

#endif