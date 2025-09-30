#include <iostream>
#include <ctime>

#include "include/Player.h"
#include "include/NPC.h"
#include "include/Battle.h"
#include "include/GameMemory.h"

int main(void) {
    srand(static_cast<unsigned>(time(nullptr)));

    Attacks attacks;
    Player player;
    std::vector<NPC> npcs;
    
    GameMemory::loadFromMemory(player, npcs, attacks);

    Battle battle = Battle(player, npcs);
    battle.runBattle();

    GameMemory::saveToMemory(player, npcs, attacks);

    return 0;
}