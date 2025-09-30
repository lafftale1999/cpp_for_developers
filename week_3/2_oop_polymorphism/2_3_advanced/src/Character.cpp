#include "../include/Character.h"

#include <cstdlib>
#include <sstream>

Character::Character(){}

Character::Character(std::string name, int healthPoints,
                     int defensePoints, int attackPoints, Attacks attacks)
: name(std::move(name)),
  healthPoints(healthPoints),
  currentHealthPoints(healthPoints),
  defencePoints(defensePoints),
  attackPoints(attackPoints),
  isAlive(true),
  attacks(std::move(attacks))
{
    if (this->name.empty() || this->healthPoints < 1 ||
        this->defencePoints < 0 || this->attackPoints < 0) {
        throw std::invalid_argument("Unable to initialize character");
    }
}

void Character::resetCharacter() {
    currentHealthPoints = healthPoints;
    isAlive = true;
}

void Character::updateHealthPoints(int amount) {
    this->currentHealthPoints += amount;

    if (currentHealthPoints < 0) {
        currentHealthPoints = 0;
        this->isAlive = false;
    }
}

int Character::attackEnemy(Character& enemy, const Attack& attack) {
    int attackDamage = attack.getDamage();
    int enemyDefence = enemy.getDefencePoints();
    int divisor = std::max(1, enemyDefence / 2);
    int modifier = rand() % (divisor);
    int totalDamage = (attackDamage - enemyDefence) - modifier + getAttackPoints();
    
    if (totalDamage < 0) totalDamage = 0;

    enemy.updateHealthPoints(0 - totalDamage);
    return totalDamage;
}

void Character::updateStats(int healthPoints, int defencePoints, int attackPoints) {
    this->healthPoints += healthPoints;
    this->currentHealthPoints = this->healthPoints;
    this->defencePoints += defencePoints;
    this->attackPoints += attackPoints;
}

const std::string& Character::getName() const {
    return this->name;
}

int Character::getHealthPoints() const {
    return this->healthPoints;
}

int Character::getCurrentHealthPoints() const {
    return this->currentHealthPoints;
}

int Character::getDefencePoints() const {
    return this->defencePoints;
}

int Character::getAttackPoints() const {
    return this->attackPoints;
}

bool Character::getIsAlive() const {
    return this->isAlive;
}

const Attacks& Character::getAttacks() const {
    return this->attacks;
}

std::string Character::toCSVstring() const {
    std::ostringstream oss;

    oss << getName() << ","
        << getHealthPoints() << ","
        << getDefencePoints() << ","
        << getAttackPoints() << ",";
    
    for (const auto& attack : getAttacks().getAllAttacks()) {
        oss << "," << attack.getAttackId();
    }

    oss << "\n";

    return oss.str();
}
