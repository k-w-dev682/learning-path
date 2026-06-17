#include <iostream>

void arrayReverser(int numbers[], int size);
void arrayDisplay(int numbers[], int size);

int main() {
    int Numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::cout << "Array before reversing: " << '\n';

    arrayDisplay(Numbers, 10);

    std::cout << "Array after reversing: " << '\n';

    arrayReverser(Numbers, 10);
    arrayDisplay(Numbers, 10);

    return 0;
}

void arrayReverser(int Numbers[], int size) {
    for(int i = 0; i < size / 2; i++) {
        int temp = Numbers[i];
        Numbers[i] = Numbers[size - 1 - i];
        Numbers[size - 1 - i] = temp;
    }
}

void arrayDisplay(int numbers[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << '\n';
}