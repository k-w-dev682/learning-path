#include <iostream>
#include <ctime>

int numberGenerator();

int main() {
    srand(time(0));
    
    int number = numberGenerator();
    int guess = 0;
    int score = 0;

    while(guess != number) {
        std::cout << "Guess number: ";
        std::cin >> guess;
        if(guess > number) {
            std::cout << "Too much!\n";
            score++;
        } 
        else if (guess < number){
            std::cout << "Too little!\n";
            score++;
        } else {
            std::cout << "Correct! " << "Your score is: " << score;
        }
    }

    return 0;
}

int numberGenerator() {
    int randomNumber = (rand() % 100) + 1;

    return randomNumber;
}
