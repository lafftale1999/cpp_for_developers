#include "../include/Attack.h"

#include <cstdint>
#include <sstream>

int Attack::attackIdCounter = 0;

Attack::Attack(std::string name, int damage) {
    setName(name);
    setDamage(damage);
    attackId = attackIdCounter++;
}

Attack::Attack(std::string name, int damage, int attackId) {
    setName(name);
    setDamage(damage);
    this->attackId = attackId;
    if (attackIdCounter <= attackId) attackIdCounter = attackId + 1;
}

void Attack::setName(const std::string& name) {
    uint8_t len = name.length();

    if (name.empty() ||
        len < ATTACK_NAME_MIN_LEN ||
        len > ATTACK_NAME_MAX_LEN) {
            throw std::invalid_argument("Character name invalid");
    }

    this->name = name;
}

void Attack::setDamage(const int& damage) {
    if (damage < 0) {
        throw std::invalid_argument("Damage must have a positive number");
    }

    this->damage = damage;
}

const std::string& Attack::getName() const {
    return this->name;
}

int Attack::getDamage() const {
    return this->damage;
}

int Attack::getAttackId() const {
    return this->attackId;
}

std::string Attack::toCSVstring() const {
    std::ostringstream oss;

    oss << name << ","
        << damage << ","
        << attackId << "\n";

    return oss.str();
}