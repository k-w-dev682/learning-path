#include <iostream>
#include <ctime>

void passwordGenerator(int length, std::string characters);

int main() {
    srand(time(0));

    std::string characters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM[{]};:',<.>/?!@#$%^&*()-_=+1234567890";
    int length;

    std::cout << "Length of the password: ";
    std::cin >> length;

    passwordGenerator(length, characters);

    return 0;
}
void passwordGenerator(int length, std::string characters) {
    for(int i = 0; i < length; i++) {
        int random = rand() % characters.length();
        std::cout << characters[random];
    }
    std::cout << '\n';
}