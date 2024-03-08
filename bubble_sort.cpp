#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;

// Function to perform bubble sort on array A of size n
void bubbleSort(int A[], int n) {
    // Outer loop for passes through the array
    for (int i = 0; i < n - 1; i++) {
        int swap = 0; // Variable to track whether any swaps occurred during this pass

        // Inner loop for comparisons and swapping
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements and swap if necessary
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;

                swap = 1; // Set swap to 1 indicating a swap occurred
            }
        }

        // If no swaps occurred in this pass, the array is already sorted
        if (swap == 0) {
            break;
        }
    }
}

int main() {
    // Array sizes to test
    const int sizes[] = {10, 100, 1000, 10000};

    // Number of repetitions for each array size
    const int repetitions = 100;

    // Loop through the array sizes
    for (int i = 0; i < 4; i++) {
        // Create a dynamic array of the current size
        int* array = new int[sizes[i]];

        // Initialize array with random values
        for (int j = 0; j < sizes[i]; j++) {
            array[j] = rand() % 1000;
        }

        // Measure the time taken by Bubble Sort (averaged over repetitions)
        auto total_duration = chrono::microseconds(0);
        for (int rep = 0; rep < repetitions; rep++) {
            // Create a copy of the original array for each repetition
            int* tempArray = new int[sizes[i]];
            copy(array, array + sizes[i], tempArray);

            auto start_time = chrono::high_resolution_clock::now();
            bubbleSort(tempArray, sizes[i]);
            auto end_time = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            // Release memory allocated for the temporary array
            delete[] tempArray;
        }

        // Print the time taken by Bubble Sort for the current array size (averaged over repetitions)
        cout << "Average time taken by Bubble Sort for array size " << sizes[i] << ": "
             << total_duration.count() / repetitions << " microseconds\n";

        // Release memory allocated for the original array
        delete[] array;
    }

    return 0;
}
