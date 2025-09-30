#ifndef ATTACKS_H
#define ATTACKS_H

#include <vector>
#include <initializer_list>

#include "Attack.h"


class Attacks {
private:
    std::vector<Attack> attacks;

public:
    Attacks();
    Attacks(std::initializer_list<Attack> attacks);
    Attacks(const std::vector<Attack>& attacks);

    const std::vector<Attack>& getAllAttacks() const;
    const Attack* getAttack(int attackId) const;
    const Attack* getAttack(std::string attackName) const;
    void addAttack(const Attack& attack);
};

#endif