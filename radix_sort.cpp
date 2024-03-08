#include<iostream>
#include<chrono>
using namespace std;

// Function to find the maximum element in the array
int getMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Count sort to do sorting based on the digits
void countSort(int A[], int n, int pos) {
    const int k = 10; // Assuming base 10 for digits
    int count[k] = {0};

    // Count occurrences of digits at the current position
    for (int i = 0; i < n; i++) {
        ++count[(A[i] / pos) % k]; 
    }

    // Cumulative sum to get the correct position of elements in the sorted array
    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    int B[n];  

    // Build the sorted array B using count array
    for (int i = n - 1; i >= 0; i--) {
        B[--count[(A[i] / pos) % k]] = A[i];
    }

    // Copy the sorted array back to A
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

// Radix sort function
void radixSort(int A[], int n) {
    int max = getMax(A, n);

    // Perform counting sort for each digit position (from least significant to most significant)
    for (int pos = 1; max / pos > 0; pos *= 10) {
        countSort(A, n, pos);
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

            // Measure the time taken by Radix Sort
            auto start_time = chrono::high_resolution_clock::now();
            radixSort(array, sizes[i]);
            auto end_time = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            // Release memory allocated for the array
            delete[] array;
        }

        // Calculate the average time taken by Radix Sort for the current array size
        auto average_duration = total_duration.count() / repetitions;

        // Print the results
        cout << "Average time taken by Radix Sort for array size " << sizes[i] << ": "
             << average_duration << " microseconds\n\n";
    }

    return 0;
}
