#ifndef PLAYER_H_
#define PLAYER_H_

#include "Character.h"

class Player : public Character {
private:
    int experiencePoints;
    int experienceCap;
    int level;

public:
    Player(const Character& character);
    Player(const Character& character, int level, int experiencePoints, int experienceCap);
    Player();
    
    void levelUp();
    void addExperiencePoints(int experiencePoints);
    std::string toCSVstring() const override;

    int getLevel() const;
    int getExperiencePoints() const;
    int getExperienceCap() const;
};

#endif