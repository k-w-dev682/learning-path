#include <iostream>
#include <ctime>
#include <cstdlib>

class Player {
    public: 
        int lvl = 1;
        int maxHp = lvl * 10 + ((lvl * 10) / 2); 
        int hp = maxHp;

        int baseAttack = 10; 
        int defense = lvl + 8;
        int speed = lvl + 9;
        int agility = lvl + 5;

        int gold = 0;
        int exp = 0;

        int getAttackPower() {
            return (rand() % baseAttack) + 1;
        }
};

class Goblin {
    public:
        int lvl = 1;
        int maxHp = lvl * 10 + ((lvl * 10) / 2);
        int hp = maxHp;
        int goldDrop = lvl + 1;
        int expDrop = 5 * lvl - (lvl / 2);

        int baseAttack = 5;
        int defense = lvl + 4;
        int speed = lvl + 1;
        int agility = lvl;

        int getAttackPower() {
            return (rand() % baseAttack) + 1;
        }
};

int main() {
    srand(time(0));

    Player player;
    std::cout << "Welcome to the dungeon!\n";
    std::cout << "Your HP: " << player.hp << "/" << player.maxHp << "\n\n";

    while (player.hp > 0) {
        char move = ' ';

        std::cout << "======================================================\n";
        std::cout << "STATUS: HP [" << player.hp << "/" << player.maxHp << "] | Gold [" << player.gold << "] | EXP [" << player.exp << "]\n";
        std::cout << "======================================================\n";
        std::cout << "Make your move (W, A, S, D) or 'Q' to quit: ";
        std::cin >> move;

        if (move == 'q' || move == 'Q') {
            std::cout << "You coward... escaping the dungeon with " << player.gold << " gold.\n";
            break;
        }

        while(move != 'w' && move != 'a' && move != 's' && move != 'd' && move != 'W' && move != 'A' && move != 'S' && move != 'D') {
            std::cout << "Wrong move! Make your move (WASD): ";
            std::cin >> move;
        }

        std::cout << "\nYou moved successfully through the dark corridor...\n";

        if(rand() % 2 == 0) {
            Goblin goblin;
            std::cout << "An aggressive Goblin (lvl " << goblin.lvl << ") jumps out of the shadows!\n\n";

            while(player.hp > 0 && goblin.hp > 0) {
                
                if (player.speed >= goblin.speed) {
                    int playerDamage = player.getAttackPower() - goblin.defense;
                    if (playerDamage < 1) playerDamage = 1;

                    goblin.hp -= playerDamage;
                    std::cout << "You swing your sword and deal " << playerDamage << " damage to the Goblin!\n";
                    std::cout << "Goblin HP: " << (goblin.hp < 0 ? 0 : goblin.hp) << "/" << goblin.maxHp << "\n";

                    if (goblin.hp <= 0) {
                        std::cout << "\n You defeated the Goblin!\n";
                        player.gold += goblin.goldDrop;
                        player.exp += goblin.expDrop;
                        std::cout << "Found: +" << goblin.goldDrop << " Gold, +" << goblin.expDrop << " EXP\n\n";
                        break;
                    }

                    int goblinDamage = goblin.getAttackPower() - player.defense;
                    if (goblinDamage < 1) goblinDamage = 1;

                    player.hp -= goblinDamage;
                    std::cout << "Goblin hits you back for " << goblinDamage << " damage!\n";
                    std::cout << "Player HP: " << (player.hp < 0 ? 0 : player.hp) << "/" << player.maxHp << "\n\n";
                    
                    if (player.hp <= 0) {
                        std::cout << " You died in the depths of the dungeon...\n";
                        break;
                    }
                } 
                else {
                    int goblinDamage = goblin.getAttackPower() - player.defense;
                    if (goblinDamage < 1) goblinDamage = 1;

                    player.hp -= goblinDamage;
                    std::cout << "Goblin lunges first and deals " << goblinDamage << " damage!\n";
                    std::cout << "Player HP: " << (player.hp < 0 ? 0 : player.hp) << "/" << player.maxHp << "\n";

                    if (player.hp <= 0) {
                        std::cout << "You died in the depths of the dungeon...\n";
                        break;
                    }

                    int playerDamage = player.getAttackPower() - goblin.defense;
                    if (playerDamage < 1) playerDamage = 1;

                    goblin.hp -= playerDamage;
                    std::cout << "You counterattack for " << playerDamage << " damage!\n";
                    std::cout << "Goblin HP: " << (goblin.hp < 0 ? 0 : goblin.hp) << "/" << goblin.maxHp << "\n\n";

                    if (goblin.hp <= 0) {
                        std::cout << "\n You defeated the Goblin!\n";
                        player.gold += goblin.goldDrop;
                        player.exp += goblin.expDrop;
                        std::cout << "Found: +" << goblin.goldDrop << " Gold, +" << goblin.expDrop << " EXP\n\n";
                        break;
                    }
                }
                
                std::cout << "Press Enter to continue the fight...";
                std::cin.get();
                std::cin.ignore();
                std::cout << "\n--------------------\n";
            }
        } 
        else {
            std::cout << "The corridor is quiet... No monsters here. You can catch your breath.\n\n";
        }
    }

    std::cout << "=====================================\n";
    std::cout << "             GAME OVER               \n";
    std::cout << "=====================================\n";

    return 0;
}