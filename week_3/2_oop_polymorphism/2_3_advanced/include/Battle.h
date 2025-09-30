#ifndef BATTLE_H_
#define BATTLE_H_

#include <memory>
#include <deque>
#include <vector>
#include <string>
#include <initializer_list>

#include "Player.h"
#include "NPC.h"

class Battle {
private:
    // Smart pointers that dies when out of scope.
    Player* player; 
    std::unique_ptr<NPC> currentEnemy;
    std::vector<NPC> possibleOpponents;
    std::deque<std::string> attackHistory;

    void logAttack(const Character& attacker, const Character& defender, const Attack& attack, const int damage);
    void exchangeBlows(const int userInput);

public:
    Battle(Player& player, std::initializer_list<NPC> npcs);
    Battle(Player& player, const std::vector<NPC>& npcs);

    void chooseOpponent();
    void renderBattle();
    void runBattle();
    bool checkGameStatus();
};

#endif