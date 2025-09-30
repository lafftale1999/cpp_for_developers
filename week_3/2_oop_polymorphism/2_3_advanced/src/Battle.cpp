#include "../include/Battle.h"

#include <limits>
#include <string>

Battle::Battle(Player& player, std::initializer_list<NPC> npcs)
:   player(&player),
    possibleOpponents(npcs)
{
    attackHistory = {};
}

Battle::Battle(Player& player, const std::vector<NPC>& npcs) 
:   player(&player),
    possibleOpponents(npcs)
{
    attackHistory = {};
}

static void tinyClear() {
    for(int i = 0; i < 50;i++) {std::cout << '\n';}
}

static int getUserInput(int range) {
    int userInput = 0;

    while (true) {
        std::cout << "Enter choice (between 1 and " << range << ", 0 to quit): ";

        if (std::cin >> userInput) {
            if (userInput == 0) return 0;
            if (userInput > 0 && userInput <= range) return userInput;

            std::cout << "Invalid choice, try again.\n";
        } else {
            std::cout << "Invalid input, try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
}

void Battle::chooseOpponent() {
    if (possibleOpponents.empty()) {
        throw std::runtime_error("No opponents available");
    }

    int range = rand() % possibleOpponents.size();
    currentEnemy = std::make_unique<NPC>(possibleOpponents[range]);

    attackHistory.clear();
}

void Battle::logAttack(const Character& attacker, const Character& defender, const Attack& attack, const int damage) {
    std::string message = attacker.getName() + " attacked " + defender.getName() +
        " with " + attack.getName() +
        " for " + std::to_string(damage) + " damage\n";

    attackHistory.push_front(message);
}

void Battle::exchangeBlows(const int userInput) {
    const Attack& playerAttack = player->getAttacks().getAllAttacks()[userInput - 1];
    int playerDamage = player->attackEnemy(*currentEnemy, playerAttack);
    logAttack(*player, *currentEnemy, playerAttack, playerDamage);
    
    const Attack& enemyAttack = currentEnemy->generateAttack();
    int enemyDamage = currentEnemy->attackEnemy(*player, enemyAttack);
    logAttack(*currentEnemy, *player, enemyAttack, enemyDamage);
}

void Battle::renderBattle() {
    
    chooseOpponent();
    
    while (true) {
        tinyClear();

        std::cout << "--------------------------------- " << player->getName() << " vs " << currentEnemy->getName() << " ---------------------------------\n";
        std::cout << player->getName() << "\t Lvl." << player->getLevel() << "\t\t\t\t" << currentEnemy->getName() << '\n';
        std::cout << "HP: " << player->getCurrentHealthPoints() << "\t\t\t\t\t\tHP:" << currentEnemy->getCurrentHealthPoints() << '\n';
        std::cout << "ATK: " << player->getDefencePoints() << "\t\t\t\t\tATK:" << currentEnemy->getDefencePoints() << '\n';
        std::cout << "DEF: " << player->getAttackPoints() << "\t\t\t\t\tDEF:" << currentEnemy->getAttackPoints() << '\n';
        std::cout << "--------------------------------- History ----------------------------------------------\n";
        
        auto it_end = (attackHistory.size() < 4) ? attackHistory.end() : attackHistory.begin() + 4;

        for (auto it = attackHistory.begin(); it < it_end; it++) {
            std::cout << *it;
        }

        std::cout << "--------------------------------- Attacks ----------------------------------------------\n";
        int index = 1;
        auto& attacks = player->getAttacks().getAllAttacks();

        for(const auto& attack : attacks) {
            std::cout << index++ << ". " << attack.getName() << '\n';
        }

        if (checkGameStatus()) {
            int userInput = getUserInput(attacks.size());

            if (userInput == 0) break;
            else {
                exchangeBlows(userInput);
            }
        }

        else {
            if (!player->getIsAlive()) {
                std::cout << player->getName() << " was defeated!\n";
                break;
            } else if (!currentEnemy->getIsAlive()) {
                std::cout
                    << currentEnemy->getName() << " was defeated! Gained "
                    << currentEnemy->getExperienceValue() << " XP.\n";
                
                player->addExperiencePoints(currentEnemy->getExperienceValue());
                currentEnemy.reset();
                break;
            }
        }
    }

    std::cout << "\nPress Enter to continue back to main menu!";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

}

void Battle::runBattle() {

    while(true) {
        std::vector<std::string> menuOptions = {"Battle", "Exit Game"};
        player->resetCharacter();
        tinyClear();

        std::cout << "-------------------------------- CHARACTER INFORMATION -------------------------------------\n";
        std::cout << "Name: " << player->getName() << "\t\t Level: " << player->getLevel() << std::endl;
        std::cout << "HP: " << player->getHealthPoints() << std::endl;
        std::cout << "Defense: " << player->getDefencePoints() << std::endl;
        std::cout << "Attack: " << player->getAttackPoints() << std::endl;
        std::cout << "Experience: " << player->getExperiencePoints() << " / " << player->getExperienceCap() << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------\n";

        int index = 1;
        for(const auto& option : menuOptions) {
            std::cout << index++ << ". " << option << '\n';
        }

        int userInput = getUserInput(menuOptions.size());
        
        if (userInput == 0 || userInput == 2) {
            break;
        }
        else if (userInput == 1) { 
            chooseOpponent();
            renderBattle();
        }
    }
}

bool Battle::checkGameStatus() {
    return 
        player && player->getIsAlive() &&
        currentEnemy &&  currentEnemy->getIsAlive();
}