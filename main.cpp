#include <iostream>
#include "selection_sort.cpp"
#include "bubble_sort.cpp"
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

    cout << "\nArray After Sorting:\n";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }

    return 0;
}