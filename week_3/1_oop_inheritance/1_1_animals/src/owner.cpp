#include "../include/owner.h"

Owner::Owner(std::string n, std::string p, Animal a)
: name(n), phone(p), animal(a) {
    if (name.empty() ||
        phone.empty() ||
        animal.getName().empty() ||
        animal.getSound().empty() ||
        animal.getAge() <= 0) {
            throw std::invalid_argument("Unable to instantiate Owner");
    }
}