#include <iostream>
#include <chrono>
#include <thread>

int main() {
    int safeCode = 2580;
    int userSafeCode = 0;
    int attempts = 3;

    while(userSafeCode != safeCode) {
        std::cout << "Type safe code: ";
        std::cin >> userSafeCode;

        if(userSafeCode == safeCode) {
            std::cout << "You've guessed safe code!";
            break;
        } else {
            attempts--;
            std::cout << "Wrong! Number of attempts left: " << attempts << '\n';   
        }

        if(attempts == 0) {
            std::cout << "You have used all your attempts! Your penalty is to wait 10 seconds!";
            std::this_thread::sleep_for(std::chrono::seconds(10));
            std::cout << '\n';
            attempts = 3;
        }
    } 

    return 0;
}