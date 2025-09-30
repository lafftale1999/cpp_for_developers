#include "../include/Player.h"

Player::Player() {}

Player::Player(const Character& character)
: Character(std::move(character)){
    experiencePoints = 0;
    level = 1;
    experienceCap = 100;
}

Player::Player(const Character& character, int level, int experiencePoints, int experienceCap)
: Character(std::move(character)), experiencePoints(experiencePoints), experienceCap(experienceCap), level(level) {
    if (level <= 0 ||
        experiencePoints < 0 ||
        experienceCap <= 0) {
            throw std::invalid_argument("Unable to create player");
        }
}

void Player::levelUp() {
    int healthIncrease = level * 10;
    int defenseIncrease = level * 5;
    int attackIncrease = level * 10;
    
    updateStats(healthIncrease, defenseIncrease, attackIncrease);

    level++;
    experienceCap = level * 100;
    experiencePoints = 0;
    std::cout << getName() << " leveled up to level " << level << '\n';
}

void Player::addExperiencePoints(int gained) {
    int remaining = gained;

    while (remaining > 0) {
        const int need = experienceCap - experiencePoints;

        if (remaining >= need) {
            experiencePoints += need;
            remaining -= need;
            levelUp();
        } else {
            experiencePoints += remaining;
            remaining = 0;
        }
    }
}

int Player::getExperienceCap() const {
    return this->experienceCap;
}

int Player::getExperiencePoints() const {
    return this->experiencePoints;
}

int Player::getLevel() const {
    return this->level;
}

std::string Player::toCSVstring() const {
    std::ostringstream oss;

    oss << getName() << ","
        << getHealthPoints() << ","
        << getDefencePoints() << ","
        << getAttackPoints() << ","
        << level << ","
        << experiencePoints << ","
        << experienceCap;
    
    for (const auto& attack : getAttacks().getAllAttacks()) {
        oss << "," << attack.getAttackId();
    }

    oss << "\n";

    return oss.str();
}