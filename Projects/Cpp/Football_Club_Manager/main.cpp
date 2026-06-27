#include <iostream>
#include <ctime>
#include <iomanip>

class Player {
    public:
        std::string name;
        std::string position;
        int form;
        int goals;

        void train() {
            form += 5;
            if(form > 100) {
                form = 100;
            }
        }
};

int main() {
    srand(time(0));

    int clubPoints = 0;
    int matchesPlayed = 0;
    int choice = 0;

    Player squad[11] = {
        {"Joan Garcia", "GK", 90, 0},
        {"Jules Kounde", "RB", 75, 0},
        {"Pau Cubarsi", "CB", 80, 0},
        {"Gerard Martin", "CB", 81, 0},
        {"Joao Cancelo", "LB", 80, 0},
        {"Pedri", "CM", 91,  0},
        {"Eric Garcia", "CDM", 85, 0},
        {"Fermin Lopez", "CAM", 88, 0},
        {"Lamine Yamal", "RW", 92, 0},
        {"Raphinha", "LW", 89, 0},
        {"Ferran Torres", "ST", 80, 0}
    };

    while(choice != 4) {
        std::cout << "1. Show squad\n";
        std::cout << "2. Train player\n";
        std::cout << "3. Play match\n";
        std::cout << "4. Quit\n";

        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::cout << std::left;
                std::cout << std::setw(18) << "NAME" << std::setw(10) << "POSITION" << std::setw(15) << "FORM (1-100)" << std::setw(8) << "GOALS" << '\n';
                for(int i = 0; i < 11; i++) {
                    std::cout << std::left;
                    std::cout << std::setw(18) << squad[i].name << std::setw(10) << squad[i].position << std::setw(15) << squad[i].form << std::setw(8) << squad[i].goals << '\n';
                }
                break;
            }

            case 2: {
                int playerChoice = 0;
                std::cout << "TRAIN A PLAYER\n";
                for(int i = 0; i < 11; i++) {
                    std::cout << i + 1 << ". " << squad[i].name << " (Current form: " << squad[i].form << ")\n";
                }
                std::cout << "Choose player to train (1-11): ";
                std::cin >> playerChoice;

                if(playerChoice < 1 || playerChoice > 11) {
                    std::cout << "Invalid player number!\n\n";
                    break;
                }

                int idx = playerChoice - 1;

                squad[idx].train();

                std::cout << "Training complete! " << squad[idx].name << "'s form increased. New form: " << squad[idx].form << "\n\n";
                break;
            }

            case 3: {
                // NAPRAWA BŁĘDU: Blokada, jeśli rozegrano już cały sezon (38 meczów)
                if (matchesPlayed >= 38) {
                    std::cout << "League has already ended! You cannot play more matches.\n\n";
                    break;
                }

                double meanForm = 0;
                double sumForm = 0;
                double opponentForm = rand() % 26 + 60;

                for(int i = 0; i < 11; i++) {
                    sumForm += squad[i].form;
                }
                meanForm = sumForm / 11.0;

                std::cout << "Your team form: " << meanForm << " vs Opponent form: " << opponentForm << '\n';
                std::cout << "Simulating match...\n\n";

                matchesPlayed++;

                if(meanForm > opponentForm) {
                    std::cout << "You won the match!\n";

                    clubPoints += 3;

                    int scoredIdx = rand() % 10 + 1;
                    squad[scoredIdx].goals++;

                    std::cout << "Goal scored by: " << squad[scoredIdx].name << "!\n";
                }
                else if(std::abs(meanForm - opponentForm) <= 3) {
                    std::cout << "It's a draw. \n";
                    clubPoints += 1;
                } else {
                    std::cout << "You lost the match\n";
                }

                std::cout << "Matches played: " << matchesPlayed << '\n';
                std::cout << "Points: " << clubPoints << '\n';

                if(matchesPlayed == 38) {
                    std::cout << "*******************\n";
                    std::cout << "***League ended!***\n";
                    std::cout << "*******************\n";
                }

                break;
            }

            case 4: {
                std::cout << "Thanks for playing!\n";
                break;
            }
            
        }
    }

    return 0;
}