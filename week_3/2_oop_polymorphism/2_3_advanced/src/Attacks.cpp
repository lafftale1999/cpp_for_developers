#include "../include/Attacks.h"

Attacks::Attacks() {}

Attacks::Attacks(std::initializer_list<Attack> attacks)
: attacks(attacks) {}

Attacks::Attacks(const std::vector<Attack>& attacks)
: attacks(attacks) {
    if (this->attacks.empty()) {
        throw std::invalid_argument("Attacks empty!");
    }
}

const Attack* Attacks::getAttack(int attackId) const {
    for(const Attack& attack : this->attacks) {
        if (attack.getAttackId() == attackId) return &attack;
    }

    return nullptr;
}

const Attack* Attacks::getAttack(std::string attackName) const {
    for (const Attack& attack : attacks) {
        if (attack.getName() == attackName) return &attack;
    }

    return nullptr;
}

void Attacks::addAttack(const Attack& attack) {
    this->attacks.emplace_back(attack);
}

const std::vector<Attack>& Attacks::getAllAttacks() const {
    return this->attacks;
}