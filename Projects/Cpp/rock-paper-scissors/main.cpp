#include <iostream>
#include <ctime>

int main() {
    srand(time(0));

    int playerScore = 0;
    int computerScore = 0;
    int playerMove = 0;
    int computerMove = 0;

    while(playerScore < 3 && computerScore < 3) {
        
        playerMove = 0; 

        while(playerMove > 3 || playerMove < 1) {
            std::cout << "Your move (1 - rock, 2 - paper, 3 - scissors): ";
            std::cin >> playerMove;

            if (playerMove > 3 || playerMove < 1) {
                std::cout << "Wrong number! Try again.\n";
            }
        }

        computerMove = (rand() % 3) + 1;

        if(playerMove == 1 && computerMove == 2) {
            std::cout << "Computer wins! " << '\n';
            computerScore++;
        }
        else if (playerMove == 1 && computerMove == 3) {
            std::cout << "Player wins! " << '\n';
            playerScore++;
        }
        else if(playerMove == 2 && computerMove == 3) {
            std::cout << "Computer wins! " << '\n';
            computerScore++;
        }
        else if (playerMove == 2 && computerMove == 1) {
            std::cout << "Player wins! " << '\n';
            playerScore++;
        }
        else if(playerMove == 3 && computerMove == 1) {
            std::cout << "Computer wins! " << '\n';
            computerScore++;
        }
        else if (playerMove == 3 && computerMove == 2) {
            std::cout << "Player wins! " << '\n';
            playerScore++;
        } else if(playerMove == computerMove) {
            std::cout << "Draw! " << '\n';
        }
    }

    std::cout << "Player score: " << playerScore << '\n';
    std::cout << "Computer score: " << computerScore << '\n';

    return 0;
}