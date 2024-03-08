#include <iostream>
#include <chrono>
using namespace std;

// Function to perform selection sort on array A of size n
void selectionSort(int A[], int n) {
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        // Assume the current index is the smallest
        int smallest = i;

        // Find the index of the smallest element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[smallest]) {
                smallest = j;
            }
        }

        // Swap the found smallest element with the current element
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
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

            // Measure the time taken by Selection Sort
            auto start_time = chrono::high_resolution_clock::now();
            selectionSort(array, sizes[i]);
            auto end_time = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            // Release memory allocated for the array
            delete[] array;
        }

        // Calculate the average time taken by Selection Sort for the current array size
        auto average_duration = total_duration.count() / repetitions;

        // Print the results
        cout << "Average time taken by Selection Sort for array size " << sizes[i] << ": "
             << average_duration << " microseconds\n\n";
    }

    return 0;
}