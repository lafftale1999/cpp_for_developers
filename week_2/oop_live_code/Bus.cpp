#include "Bus.h"

Bus::Bus(std::string model) {
    this->model = model;
}

void Bus::honk() {
    std::cout << "HONK!\n";
}

bool operator==(const Bus& b1, const Bus& b2) {
    return b1.model == b2.model;
}