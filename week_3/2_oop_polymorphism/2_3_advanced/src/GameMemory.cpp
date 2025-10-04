#include "../include/GameMemory.h"

#include <fstream>
#include <string>
#include <sstream>

std::string memoryDirectory = "memory";
std::string playerFilePath = memoryDirectory + "/player.csv";
std::string npcFilePath = memoryDirectory + "/npcs.csv";
std::string attacksFilePath = memoryDirectory + "/attacks.csv";

enum playerValues {
    PLAYER_NAME,
    PLAYER_HEALTH_POINTS,
    PLAYER_DEFENSE_POINTS,
    PLAYER_ATTACK_POINTS,
    PLAYER_LEVEL,
    PLAYER_EXP,
    PLAYER_EXP_CAP,
    PLAYER_ATTACK_ID_S
};

enum characterValues {
    CHAR_NAME,
    CHAR_HEALTH_POINTS,
    CHAR_DEFENSE_POINTS,
    CHAR_ATTACK_POINTS,
    CHAR_EXP_VALUE,
    CHAR_ATTACK_ID_S
};

enum attackValues {
    ATK_NAME,
    ATK_DMG,
    ATK_ID
};

using valuesVector = std::vector<std::vector<std::string>>; 

static bool playerParser(const valuesVector& loadedValues, Player& player, const Attacks& attacks) {
    if (!loadedValues.empty()) {
        for (const auto& row : loadedValues) {
            std::string name = row[PLAYER_NAME];
            int healthPoints = std::stoi(row[PLAYER_HEALTH_POINTS]);
            int defensePoints = std::stoi(row[PLAYER_DEFENSE_POINTS]);
            int attackPoints = std::stoi(row[PLAYER_ATTACK_POINTS]);
            int level = std::stoi(row[PLAYER_LEVEL]);
            int experience = std::stoi(row[PLAYER_EXP]);
            int experience_cap = std::stoi(row[PLAYER_EXP_CAP]);
            std::vector<Attack> loadedAttacks;

            for (auto it = row.begin() + PLAYER_ATTACK_ID_S; it < row.end(); it++) {
                if (const Attack* attack = attacks.getAttack(std::stoi(*it))) {
                    loadedAttacks.push_back(*attack);
                } else {
                    throw std::invalid_argument("Unable to find attack with id " + std::stoi(*it));
                }
            }

            player = Player(Character(name, healthPoints, defensePoints, attackPoints, Attacks(loadedAttacks)), level, experience, experience_cap);
            return true;
        }
    }

    return false;
}

static bool npcParser(const valuesVector& loadedValues, std::vector<NPC>& NPCs, const Attacks& attacks) {
    bool hasParsed = false;

    for (const auto& row : loadedValues) {
        std::string name = row[CHAR_NAME];
        int healthPoints = std::stoi(row[CHAR_HEALTH_POINTS]);
        int defensePoints = std::stoi(row[CHAR_DEFENSE_POINTS]);
        int attackPoints = std::stoi(row[CHAR_ATTACK_POINTS]);
        int experienceValue = std::stoi(row[CHAR_EXP_VALUE]);

        std::vector<Attack> loadedAttacks;

        for (auto it = row.begin() + CHAR_ATTACK_ID_S; it < row.end(); it++) {
            if (const Attack* attack = attacks.getAttack(std::stoi(*it))) {
                loadedAttacks.push_back(*attack);
            }
            else {
                throw std::invalid_argument("Unable to find attack with id " + std::stoi(*it));
            }
        }

        NPCs.push_back(NPC(Character(name, healthPoints, defensePoints, attackPoints, Attacks(loadedAttacks)), experienceValue));

        hasParsed = true;
    }

    return hasParsed;
}

static bool attackParser(const valuesVector& loadedValues, std::vector<Attack>& attacks) {
    bool hasParsed = false;

    for (const auto& row : loadedValues) {
        std::string name = row[ATK_NAME];
        int damage = std::stoi(row[ATK_DMG]);
        int id = std::stoi(row[ATK_ID]);

        attacks.push_back(Attack(name, damage, id));

        hasParsed = true;
    }

    return hasParsed;
}

static bool loadValuesFromMemory(valuesVector& loadedValues, std::string path) {
    bool valuesLoaded = false;
    
    std::ifstream file(path);

    if (!file.is_open()) {
        return valuesLoaded;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> loadedRow;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            loadedRow.emplace_back(cell);
        }

        loadedValues.emplace_back(loadedRow);
        valuesLoaded = true;
    }

    file.close();

    return valuesLoaded;
}

bool GameMemory::loadAttacks(std::vector<Attack>& attacks) {
    valuesVector loadedValues;
    
    return 
        loadValuesFromMemory(loadedValues, attacksFilePath) &&
        attackParser(loadedValues, attacks);
}

bool GameMemory::loadPlayer(Player& player, const Attacks& attacks) {
    valuesVector loadedValues;
    
    return 
        loadValuesFromMemory(loadedValues, playerFilePath) &&
        playerParser(loadedValues, player, attacks);
}

bool GameMemory::loadNpcs(std::vector<NPC>& npcs, const Attacks& attacks) {
    valuesVector loadedValues;
    
    return 
        loadValuesFromMemory(loadedValues, npcFilePath) &&
        npcParser(loadedValues, npcs, attacks);
}

bool GameMemory::loadFromMemory(Player& player, std::vector<NPC>& npcs, Attacks& attacks) {
    
    std::vector<Attack> tempAttacks;
    if (loadAttacks(tempAttacks)) {
        attacks = Attacks(tempAttacks);
    } else return false;
    loadPlayer(player, attacks);
    loadNpcs(npcs, attacks);
    
    return true;
}

static void writeToMemory(std::vector<std::string>& lines, std::string filePath) {
    std::ofstream file(filePath);

    if (!file.is_open()) {
        return;
    }

    for (const auto& line : lines) {
        file << line;
    }

    file.close();
}

void GameMemory::saveAttacks(const Attacks& attacks) {
    
    std::vector<std::string> lines;

    for (const auto& attack : attacks.getAllAttacks()) {
        lines.emplace_back(attack.toCSVstring());
    }
    
    writeToMemory(lines, attacksFilePath);
}

void GameMemory::savePlayer(const Player& player) {
    
    std::vector<std::string> lines = {player.toCSVstring()};
    
    writeToMemory(lines, playerFilePath);
}

void GameMemory::saveNpcs(const std::vector<NPC>& npcs) {
    std::vector<std::string> lines;

    for (const auto& npc : npcs) {
        lines.emplace_back(npc.toCSVstring());
    }

    writeToMemory(lines, npcFilePath);
}

bool GameMemory::saveToMemory(const Player& player, const std::vector<NPC>& npcs, const Attacks& attacks) {
    saveAttacks(attacks);
    savePlayer(player);
    saveNpcs(npcs);

    return true;
}