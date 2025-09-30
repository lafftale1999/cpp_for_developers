#ifndef GAME_MEMORY_H_
#define GAME_MEMORY_H_

#include <iostream>
#include <vector>

#include "Player.h"
#include "NPC.h"
#include "Attacks.h"

class GameMemory {
private:
    static bool loadPlayer(Player& player, const Attacks& attacks);
    static bool loadNpcs(std::vector<NPC>& npcs, const Attacks& attacks);
    static bool loadAttacks(std::vector<Attack>& attacks);

    static void savePlayer(const Player& player);
    static void saveAttacks(const Attacks& attacks);
    static void saveNpcs(const std::vector<NPC>& npcs);

public:
    static bool loadFromMemory(Player& player, std::vector<NPC>& npcs, Attacks& attacks);
    static bool saveToMemory(const Player& player, const std::vector<NPC>& npcs, const Attacks& attacks);
};

#endif