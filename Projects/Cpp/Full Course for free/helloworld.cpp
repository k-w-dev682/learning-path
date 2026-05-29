#include <iostream>
#include <vector>

int main() {
    std::string name;
    std::cout<<"What's your full name?: ";
    std::getline(std::cin, name);
    std::cout<<name;
}