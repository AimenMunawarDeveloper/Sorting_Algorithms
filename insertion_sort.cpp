#include <iostream>
#include <chrono>
using namespace std;

// Function to perform insertion sort on array A of size n
void insertionSort(int A[], int n) {
    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++) {
        int key = A[i];  // Current element to be inserted into the sorted sequence
        int j = i - 1;    // Index of the last element in the sorted sequence

        // Compare the current element with elements in the sorted sequence and shift them if necessary
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];  // Shift the element to the right
            j--;              // Move to the previous position in the sorted sequence
        }

        A[j + 1] = key;  // Insert the key into its correct position in the sorted sequence
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

            // Measure the time taken by insertion Sort
            auto start_time = chrono::high_resolution_clock::now();
            insertionSort(array, sizes[i]);
            auto end_time = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            // Release memory allocated for the array
            delete[] array;
        }

        // Calculate the average time taken by Insertion Sort for the current array size
        auto average_duration = total_duration.count() / repetitions;

        // Print the results
        cout << "Average time taken by Insertion Sort for array size " << sizes[i] << ": "
             << average_duration << " microseconds\n\n";
    }

    return 0;
}
