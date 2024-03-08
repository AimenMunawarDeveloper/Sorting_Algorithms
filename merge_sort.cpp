#include<iostream>
#include<climits> // Include this header for INT_MAX
#include<cmath>
#include<chrono>
using namespace std;

// Merge function to merge two sorted subarrays A[p..q] and A[q+1..r]
void merge(int A[], int p, int q, int r) {
    // ... (same as your original merge function)
}

// MergeSort function to recursively sort the array A[p..r]
void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = floor((p + r) / 2); // Calculate the midpoint of the array

        // Recursively sort the two halves
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);

        // Merge the sorted halves
        merge(A, p, q, r);
    }
}

int main() {
    // Array sizes to test
    const int sizes[] = {10, 100, 1000, 10000};

    // Number of repetitions for each array size
    const int repetitions = 100;

    // Loop through the array sizes
    for (int i = 0; i < 4; i++) {
        // Initialize total duration for averaging
        auto total_duration = chrono::microseconds(0);

        // Perform repetitions
        for (int rep = 0; rep < repetitions; rep++) {
            // Create a dynamic array of the current size
            int* array = new int[sizes[i]];

            // Initialize array with random values
            for (int j = 0; j < sizes[i]; j++) {
                array[j] = rand() % 1000;
            }

            // Measure the time taken by merge Sort
            auto start_time = chrono::high_resolution_clock::now();
            mergeSort(array, 0, sizes[i] - 1);
            auto end_time = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            // Release memory allocated for the array
            delete[] array;
        }

        // Calculate the average time taken by Merge Sort for the current array size
        auto average_duration = total_duration.count() / repetitions;

        // Print the results
        cout << "Average time taken by Merge Sort for array size " << sizes[i] << ": "
             << average_duration << " microseconds\n\n";
    }

    return 0;
}
