#include <iostream>
#include "selection_sort.cpp"
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "quick_sort.cpp"
#include "merge_sort.cpp"
#include "heap_sort.cpp"
#include "counting_sort.cpp"
using namespace std;

int main() {
    int array[10] = {4, 77, 24, 6, 2, 8, 3, 6, 4, 4};

    cout << "Array before Sorting:\n";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    
    // Call the sorting function to sort the array
    bubbleSort(array, 10);
    selectionSort(array, 10);
    insertionSort(array, 10);
    quickSort(array, 0,9);
    mergeSort(array, 0, 9);
    heapSort(array, 10);
    countingSort(array, 10, 77);

    cout << "\nArray After Sorting:\n";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    return 0;
}