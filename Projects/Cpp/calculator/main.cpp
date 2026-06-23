#include <iostream>

int main() {
    char character = ' ';
    double number = 0;
    double result = 0;

    std::cout << "Enter starting number: ";
    std::cin >> result;
    std::cout << "Current value: " << result << "\n\n";

    do {
        std::cout << "Type character (+, -, *, /) or 'q' to quit: ";
        std::cin >> character;

        if (character == 'q' || character == 'Q') {
            break;
        }

        std::cout << "Type next number: ";
        std::cin >> number;

        if (character == '/' && number == 0) {
            std::cout << "Error: Cannot divide by zero!\n";
            std::cout << "Result remains: " << result << "\n\n";
            continue;
        }

        switch (character) {
            case '+': result += number; break;
            case '-': result -= number; break;
            case '*': result *= number; break;
            case '/': result /= number; break;
            default:  std::cout << "Unknown operation!\n"; break;
        }

        std::cout << "Total Result: " << result << "\n\n";

    } while(character != 'q' && character != 'Q');

    std::cout << "Final Result: " << result << "\nThank you for using the calculator!\n";

    return 0;
}