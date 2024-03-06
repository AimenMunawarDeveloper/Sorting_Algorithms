#include <iostream>
#include "selection_sort.cpp"
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "quick_sort.cpp"
#include "merge_sort.cpp"
#include "heap_sort.cpp"
#include "counting_sort.cpp"
#include "radix_sort.cpp"
#include "bucket_sort.cpp"
using namespace std;


int main() {
    const int minSize = 10;
    const int maxSize = 10000;
    const int stepSize = 10;

    for (int s = minSize; s <= maxSize; s += stepSize) {
        int* array = new int[s];

        // Initialize array with random values
        for (int i = 0; i < s; i++) {
            array[i] = rand() % 1000;
        }

        cout << "Array before Sorting (first 10 elements):\n";
        for (int i = 0; i < min(s, 10); i++) {
            cout << array[i] << " ";
        }

        auto start_time = chrono::high_resolution_clock::now();
        bubbleSort(array, s);
        selectionSort(array, s);
        insertionSort(array, s);
        quickSort(array, 0, s - 1);
        mergeSort(array, 0, s - 1);
        heapSort(array, s);
        radixSort(array, s);

        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

        cout << "\nArray After Sorting (first 10 elements):\n";
        for (int i = 0; i < min(s, 10); i++) {
            cout << array[i] << " ";
        }

        cout << "\nTime taken by Bubble Sort for array size " << s << ": " << duration.count() << " microseconds\n\n";

        delete[] array;
    }

    return 0;
}