#include "../include/NPC.h"

#include <random>
#include <stdexcept>

NPC::NPC(const Character& character, const int& experienceValue)
: Character(character)
{
    if (experienceValue <= 0) {
        throw std::invalid_argument("Experience value need to be larger than 0");
    }

    this->experienceValue = experienceValue;
}

int NPC::getExperienceValue() const {
    return this->experienceValue;
}

const Attack& NPC::generateAttack() const {

    const auto& allAttacks = getAttacks().getAllAttacks();

    if (allAttacks.empty()) {
        throw std::runtime_error("NPC has no attacks!");
    }

    int index = rand() % allAttacks.size();
    int id = allAttacks.at(index).getAttackId();
    
    if (const Attack* attack = getAttacks().getAttack(id)) {
        return *attack;
    }
    
    throw std::runtime_error("Attack ID nto found in Attacks");
}

std::string NPC::toCSVstring() const {
    std::ostringstream oss;
    oss << getName() << ","
        << getHealthPoints() << ","
        << getDefencePoints() << ","
        << getAttackPoints() << ","
        << getExperienceValue();

    for (const auto& a : getAttacks().getAllAttacks()) oss << "," << a.getAttackId();
    oss << "\n";
    
    return oss.str();
}