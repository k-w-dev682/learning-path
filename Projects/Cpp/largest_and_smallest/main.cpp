#include <iostream>
#include <vector>

int Max(std::vector<int>Numbers);
int Min(std::vector<int>Numbers);

int main() {
    int number = 0;
    std::vector<int>Numbers;

    do {
        std::cout << "Type number: ";
        std::cin >> number;
        
        if(number != 0) {
            Numbers.push_back(number);
        }
        
    } while(number != 0);

    for (int j = 0; j < Numbers.size(); j++) {
        std::cout << Numbers[j] << " ";
    }
    std::cout << '\n';
    
    std::cout << "Largest: " << Max(Numbers) << '\n';
    std::cout << "Smallest: " << Min(Numbers) << '\n';

    return 0;
}

int Max(std::vector<int>Numbers) {
    int max = Numbers[0];
    for(int i = 0; i < Numbers.size(); i++) {
        if(Numbers[i] > max) {
            max = Numbers[i];
        }
    }
    return max;
}

int Min(std::vector<int>Numbers) {
    int min = Numbers[0];
    for(int i = 0; i < Numbers.size(); i++) {
        if(Numbers[i] < min) {
            min = Numbers[i];
        }
    }
    return min;
}