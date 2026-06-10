#include <iostream>

int main() {
    std::string name = "Aaa";
    int age = 21;
    std::string FreePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};

    std::string *pName = &name;
    int *pAge = &age;
    std::string *pFreePizzas = FreePizzas;

    std::cout << *pName << '\n';
    std::cout << *pAge << '\n';
    std::cout << *pFreePizzas << '\n';

    return 0;
}
    