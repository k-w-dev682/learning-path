#include <iostream>
#include <ctime>
#include <vector>

int main() {
    srand(time(0));

    int numberOfThrows;

    std::cout << "Type the number of throws: ";
    std::cin >> numberOfThrows;

    std::vector<int> Throws(numberOfThrows);

    for(int i = 0; i < numberOfThrows; i++) {
        std::cout << "Throwing the dice... ";
        Throws[i] = (rand() % 6) + 1;
        std::cout << Throws[i] << '\n';
    }

    for(int j = 0; j < numberOfThrows; j++) {
        std::cout << Throws[j] << " ";
    }

    return 0;
}