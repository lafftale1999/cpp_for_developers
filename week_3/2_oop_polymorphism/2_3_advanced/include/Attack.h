#ifndef ATTACK_H_
#define ATTACK_H_

#include <iostream>

#define ATTACK_NAME_MIN_LEN 2
#define ATTACK_NAME_MAX_LEN 50


class Attack {
private:
    std::string name;
    int damage;
    int attackId;

    static int attackIdCounter; // Generating incrementing IDs

public:
    Attack(std::string name, int damage);
    Attack(std::string name, int damage, int attackId);
    void setName(const std::string& name);
    void setDamage(const int& damage);

    const std::string& getName() const;
    int getDamage() const;
    int getAttackId() const;
    std::string toCSVstring() const;
};

#endif