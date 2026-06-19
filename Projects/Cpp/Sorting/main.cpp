#include <iostream>
#include <ctime>
#include <chrono>

void randomArray(int Numbers[], int size);
void bubbleSort(int Numbers[], int size);
void selectionSort(int Numbers[], int size);
void exchangeSort(int Numbers[], int size);
void insertionSort(int Numbers[], int size);
int partition(int Numbers[], int low, int high);
void quickSort(int Numbers[], int low, int high);
void merge(int Numbers[], int left, int mid, int right);
void mergeSort(int Numbers[], int left, int right);
void heapify(int Numbers[], int n, int i);
void heapSort(int Numbers[], int size);
void countingSort(int Numbers[], int size);
void bucketSort(int Numbers[], int size);
void printArray(const int Numbers[], int size);
void copyArray(const int source[], int destination[], int size);

int main() {
    srand(time(0));
    
    const int size = 10000; 
    
    int* Numbers = new int[size]; 
    int* workingCopy = new int[size]; 

    randomArray(Numbers, size);

    std::cout << "======================================================\n";
    std::cout << "  SORTING ALGORITHMS BENCHMARK (Array size: " << size << ")\n";
    std::cout << "======================================================\n\n";

    // --- BUBBLE SORT ---
    copyArray(Numbers, workingCopy, size);
    std::cout << "Running Bubble Sort... ";
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(workingCopy, size);
    auto end = std::chrono::high_resolution_clock::now();
    auto t_bubble = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "DONE (" << t_bubble / 1000.0 << " ms)\n";

    // --- SELECTION SORT ---
    copyArray(Numbers, workingCopy, size);
    std::cout << "Running Selection Sort... ";
    start = std::chrono::high_resolution_clock::now();
    selectionSort(workingCopy, size);
    end = std::chrono::high_resolution_clock::now();
    auto t_selection = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "DONE (" << t_selection / 1000.0 << " ms)\n";

    // --- EXCHANGE SORT ---
    copyArray(Numbers, workingCopy, size);
    std::cout << "Running Exchange Sort... ";
    start = std::chrono::high_resolution_clock::now();
    exchangeSort(workingCopy, size);
    end = std::chrono::high_resolution_clock::now();
    auto t_exchange = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "DONE (" << t_exchange / 1000.0 << " ms)\n";

    // --- INSERTION SORT ---
    copyArray(Numbers, workingCopy, size);
    std::cout << "Running Insertion Sort... ";
    start = std::chrono::high_resolution_clock::now();
    insertionSort(workingCopy, size);
    end = std::chrono::high_resolution_clock::now();
    auto t_insertion = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "DONE (" << t_insertion / 1000.0 << " ms)\n";

    // --- QUICK SORT ---
    copyArray(Numbers, workingCopy, size);
    std::cout << "Running Quick Sort... ";
    start = std::chrono::high_resolution_clock::now();
    quickSort(workingCopy, 0, size - 1);
    end = std::chrono::high_resolution_clock::now();
    auto t_quick = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "DONE (" << t_quick / 1000.0 << " ms)\n";

    // --- MERGE SORT ---
    copyArray(Numbers, workingCopy, size);
    std::cout << "Running Merge Sort... ";
    start = std::chrono::high_resolution_clock::now();
    mergeSort(workingCopy, 0, size - 1);
    end = std::chrono::high_resolution_clock::now();
    auto t_merge = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "DONE (" << t_merge / 1000.0 << " ms)\n";

    // --- HEAP SORT ---
    copyArray(Numbers, workingCopy, size);
    std::cout << "Running Heap Sort... ";
    start = std::chrono::high_resolution_clock::now();
    heapSort(workingCopy, size);
    end = std::chrono::high_resolution_clock::now();
    auto t_heap = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "DONE (" << t_heap / 1000.0 << " ms)\n";

    // --- COUNTING SORT ---
    copyArray(Numbers, workingCopy, size);
    std::cout << "Running Counting Sort... ";
    start = std::chrono::high_resolution_clock::now();
    countingSort(workingCopy, size);
    end = std::chrono::high_resolution_clock::now();
    auto t_counting = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "DONE (" << t_counting / 1000.0 << " ms)\n";

    // --- BUCKET SORT ---
    copyArray(Numbers, workingCopy, size);
    std::cout << "Running Bucket Sort... ";
    start = std::chrono::high_resolution_clock::now();
    bucketSort(workingCopy, size);
    end = std::chrono::high_resolution_clock::now();
    auto t_bucket = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "DONE (" << t_bucket / 1000.0 << " ms)\n\n";

    std::cout << "======================================================\n";
    std::cout << "  FINAL RESULTS (Time in Milliseconds)\n";
    std::cout << "======================================================\n";
    std::cout << "  Bubble Sort:    " << t_bubble / 1000.0 << " ms\n";
    std::cout << "  Selection Sort: " << t_selection / 1000.0 << " ms\n";
    std::cout << "  Exchange Sort:  " << t_exchange / 1000.0 << " ms\n";
    std::cout << "  Insertion Sort: " << t_insertion / 1000.0 << " ms\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << "  Quick Sort:     " << t_quick / 1000.0 << " ms\n";
    std::cout << "  Merge Sort:     " << t_merge / 1000.0 << " ms\n";
    std::cout << "  Heap Sort:      " << t_heap / 1000.0 << " ms\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << "  Counting Sort:  " << t_counting / 1000.0 << " ms\n";
    std::cout << "  Bucket Sort:    " << t_bucket / 1000.0 << " ms\n";
    std::cout << "======================================================\n";

    delete[] Numbers;
    delete[] workingCopy;

    return 0;
}
/*int main() {
    srand(time(0));
    int size = 10000;
    int Numbers[size]; 

    randomArray(Numbers, size);

    int workingCopy[size]; 

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Bubble Sort: \n";
    printArray(workingCopy, size);

    bubbleSort(workingCopy, size);
    std::cout << "After Bubble Sort:  \n";
    printArray(workingCopy, size);
    std::cout << '\n';

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Selection Sort: \n";
    printArray(workingCopy, size);

    selectionSort(workingCopy, size);
    std::cout << "After Selection Sort:  \n";
    printArray(workingCopy, size);
    std::cout << '\n';

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Exchange Sort: \n";
    printArray(workingCopy, size);

    exchangeSort(workingCopy, size);
    std::cout << "After Exchange Sort:  \n";
    printArray(workingCopy, size);
    std::cout << '\n';
    
    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Insertion Sort: \n";
    printArray(workingCopy, size);

    insertionSort(workingCopy, size);
    std::cout << "After Insertion Sort:  \n";
    printArray(workingCopy, size);
    std::cout << '\n';

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Quick Sort: \n";
    printArray(workingCopy, size);

    quickSort(workingCopy, 0, size - 1);
    std::cout << "After Quick Sort:  \n";
    printArray(workingCopy, size);
    std::cout << '\n';

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Merge Sort: \n";
    printArray(workingCopy, size);

    mergeSort(workingCopy, 0, size - 1);
    std::cout << "After Merge Sort:  \n";
    printArray(workingCopy, size);
    std::cout << '\n';

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Heap Sort: \n";
    printArray(workingCopy, size);

    heapSort(workingCopy, size);
    std::cout << "After Heap Sort:  \n";
    printArray(workingCopy, size);
    std::cout << '\n';

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Counting Sort: \n";
    printArray(workingCopy, size);

    countingSort(workingCopy, size);
    std::cout << "After Counting Sort:  \n";
    printArray(workingCopy, size);
    std::cout << '\n';

    copyArray(Numbers, workingCopy, size);
    std::cout << "Before Bucket Sort:   \n";
    printArray(workingCopy, size);

    bucketSort(workingCopy, size);
    std::cout << "After Bucket Sort:    \n";
    printArray(workingCopy, size);
    std::cout << '\n';

    return 0;
}*/

void randomArray(int Numbers[], int size) {
    for(int i = 0; i < size; i++) {
        int random = (rand() % 1000000) + 1;
        Numbers[i] = random;
    }
        
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

int partition(int Numbers[], int low, int high) {
    int pivot = Numbers[high];
    int i = (low - 1);

    for(int j = low; j < high; j++) {
        if(Numbers[j] <= pivot) {
            i++;
            int temp = Numbers[i];
            Numbers[i] = Numbers[j];
            Numbers[j] = temp;
        }
    }
    int temp = Numbers[i + 1];
    Numbers[i + 1] = Numbers[high];
    Numbers[high] = temp;

    return (i + 1);
} 
void quickSort(int Numbers[], int low, int high) {
    if(low < high) {
        int pi = partition(Numbers, low, high);

        quickSort(Numbers, low, pi - 1);
        quickSort(Numbers, pi + 1, high);
    }

}

void merge(int Numbers[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++) {
        L[i] = Numbers[left + i]; 
    }
    for(int j = 0; j < n2; j++) {
        R[j] = Numbers[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            Numbers[k] = L[i];
            i++;
        } else {
            Numbers[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        Numbers[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        Numbers[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
   
}
void mergeSort(int Numbers[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(Numbers, left, mid);
        mergeSort(Numbers, mid + 1, right);

        merge(Numbers, left, mid, right);
    }
}

void heapify(int Numbers[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && Numbers[left] > Numbers[largest]) {
        largest = left;
    }

    if(right < n && Numbers[right] > Numbers[largest]) {
        largest = right;
    }

    if(largest != i) {
        int temp = Numbers[i];
        Numbers[i] = Numbers[largest];
        Numbers[largest] = temp;

        heapify(Numbers, n, largest);
    }
}
void heapSort(int Numbers[], int size) {
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(Numbers, size, i);
    }

    for(int i = size - 1; i > 0; i--) {
        int temp = Numbers[0];
        Numbers[0] = Numbers[i];
        Numbers[i] = temp;

        heapify(Numbers, i, 0);
    }
}

void countingSort(int Numbers[], int size) {
    if(size <= 0) {
        return;
    }

    int max = Numbers[0];
    for(int i = 1; i < size; i++) {
        if(Numbers[i] > max) {
            max = Numbers[i];
        }
    }

    int* count = new int[max + 1]{0};

    int* output = new int[size];

    for(int i = 0; i < size; i++) {
        count[Numbers[i]]++;
    }

    for(int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--) {
        output[count[Numbers[i]] - 1] = Numbers[i];
        count[Numbers[i]]--;
    }

    for(int i = 0; i < size; i++) {
        Numbers[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

void bucketSort(int Numbers[], int size) {
    if(size <= 0) {
        return;
    }

    int minVal = Numbers[0];
    int maxVal = Numbers[0];
    for(int i = 1; i < size; i++) {
        if(Numbers[i] < minVal) minVal = Numbers[i];
        if(Numbers[i] > maxVal) maxVal = Numbers[i];
    }

    int bucketCount = size;
    int* bucketSize = new int[bucketCount]{0};

    int** buckets = new int*[bucketCount];
    for(int i = 0; i < bucketCount; i++) {
        buckets[i] = new int[size];
    }

    int range = maxVal - minVal + 1;
    for(int i = 0; i < size; i++) {
        int bucketIndex = (bucketCount * (Numbers[i] - minVal)) / range;
        if(bucketIndex >= bucketCount) {
            bucketIndex = bucketCount - 1;
        }
        buckets[bucketIndex][bucketSize[bucketIndex]] = Numbers[i];
        bucketSize[bucketIndex]++;
    }

    int index = 0;
    for(int i = 0; i < bucketCount; i++) {
        if(bucketSize[i] > 0) {
            insertionSort(buckets[i], bucketSize[i]);
            
            for(int j = 0; j < bucketSize[i]; j++) { 
                Numbers[index++] = buckets[i][j];
            }
        }
    }

    for(int i = 0; i < bucketCount; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSize;
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