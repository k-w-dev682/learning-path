#include <iostream>

void bubbleSort(int Numbers[], int size);
void selectionSort(int Numbers[], int size);
void exchangeSort(int Numbers[], int size);
void insertionSort(int Numbers[], int size);
void quickSort(int Numbers[], int size);
void mergeSort(int Numbers[], int size);
void heapSort(int Numbers[], int size);
void countingSort(int Numbers[], int size);
void bucketSort(int Numbers[], int size);
void printArray(const int Numbers[], int size);
void copyArray(const int source[], int destination[], int size);

int main() {
    const int Numbers[] = {10, 2, 3, 9, 6, 1, 3, 4, 7, 5, 8}; 
    int size = sizeof(Numbers) / sizeof(Numbers[0]);

    int workingCopy[size]; 

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Bubble Sort: ";
    printArray(workingCopy, size);

    bubbleSort(workingCopy, size);
    std::cout << "After Bubble Sort:  ";
    printArray(workingCopy, size);
    std::cout << '\n';

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Selection Sort: ";
    printArray(workingCopy, size);

    selectionSort(workingCopy, size);
    std::cout << "After Selection Sort:  ";
    printArray(workingCopy, size);
    std::cout << '\n';

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Exchange Sort: ";
    printArray(workingCopy, size);

    exchangeSort(workingCopy, size);
    std::cout << "After Exchange Sort:  ";
    printArray(workingCopy, size);
    std::cout << '\n';
    
    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Insertion Sort: ";
    printArray(workingCopy, size);

    insertionSort(workingCopy, size);
    std::cout << "After Insertion Sort:  ";
    printArray(workingCopy, size);
    std::cout << '\n';

    return 0;
}

void bubbleSort(int Numbers[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            int temp;
            if(Numbers[j] > Numbers[j + 1]) {
                temp = Numbers[j];
                Numbers[j] = Numbers[j + 1];
                Numbers[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int Numbers[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(Numbers[j] < Numbers[minIndex]) {
                minIndex = j;
            }
        }
        int temp = Numbers[i];
        Numbers[i] = Numbers[minIndex];
        Numbers[minIndex] = temp;
    }
}

void exchangeSort(int Numbers[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(Numbers[i] > Numbers[j]) {
                int temp;
                temp = Numbers[i];
                Numbers[i] = Numbers[j];
                Numbers[j] = temp;
            }
        }
    }
}

void insertionSort(int Numbers[], int size) {
    for(int i = 1; i < size; i++) {
        int key = Numbers[i];
        int j = i - 1;

        while(j >= 0 && Numbers[j] > key) {
            Numbers[j + 1] = Numbers[j];
            j--;
        }
        Numbers[j + 1] = key;
    }
}

void quickSort(int Numbers[], int size) {

}
void mergeSort(int Numbers[], int size) {

}

void heapSort(int Numbers[], int size) {

}

void countingSort(int Numbers[], int size) {

}

void bucketSort(int Numbers[], int size) {

}

void printArray(const int Numbers[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << Numbers[i] << " ";
    }
    std::cout << '\n';
}
void copyArray(const int source[], int destination[], int size) {
    for(int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}