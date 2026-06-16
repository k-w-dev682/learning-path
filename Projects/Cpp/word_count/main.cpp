#include <iostream>

int wordsCounting(std::string word);

int main() {
    std::string word;
    int numberOfWords;
    int numberOfCharacters;

    std::cout << "Type the word: ";
    std::getline(std::cin, word);

    numberOfCharacters = word.length();
    numberOfWords = wordsCounting(word);

    std::cout << "Characters: " << numberOfCharacters << '\n';
    std::cout << "Words: " << numberOfWords << '\n';


    return 0;
}

int wordsCounting(std::string word) {
    int numberOfWords = 1;
    for(int i = 0; i < word.length(); i++) {
        if(word[i] == ' ') {
            numberOfWords++;
        }
    }
    return numberOfWords;
}
