#include <iostream>

int main() {
    //std::string students[] = {"Spongebob", "Patrick", "Squidward", "Sandy"};
    int grades[] = {65, 72, 81, 93};

    for(int grade : grades) {
        std::cout << grade << '\n';
    }

    return 0;
}