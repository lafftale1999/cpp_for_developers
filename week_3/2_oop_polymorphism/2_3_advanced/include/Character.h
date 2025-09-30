#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include <vector>
#include <sstream>

#include "Attacks.h"

class Character {
private:
    std::string name;
    int healthPoints;
    int currentHealthPoints;
    int defencePoints;
    int attackPoints;
    bool isAlive;
    Attacks attacks;

protected:
    void updateHealthPoints(int amount);
    void updateStats(int healthPoints, int defencePoints, int attackPoints);

    

public:
    Character();
    Character(std::string name, int healthPoints, int defensePoints, int attackPoints, Attacks attacks);

    virtual ~Character() = default;
    int attackEnemy(Character& enemy, const Attack& attack);
    
    // abstract function
    virtual std::string toCSVstring() const;

    void resetCharacter();
    const std::string& getName() const;
    int getHealthPoints() const;
    int getCurrentHealthPoints() const;
    int getDefencePoints() const;
    int getAttackPoints() const;
    bool getIsAlive() const;
    const Attacks& getAttacks() const;
};

#endif