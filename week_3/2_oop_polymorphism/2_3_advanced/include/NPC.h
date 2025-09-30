#ifndef ENEMY_H_
#define ENEMY_H_

#include "Character.h"

class NPC : public Character {
private:
    int experienceValue;

public:
    NPC(const Character& character, const int& experienceValue);
    int getExperienceValue() const;
    const Attack& generateAttack() const;
    std::string toCSVstring() const override;
};

#endif