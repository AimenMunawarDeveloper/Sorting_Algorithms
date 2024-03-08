#include<iostream>
#include<chrono>
#include<algorithm>
using namespace std;

// Function to perform Counting Sort on an array A with 'n' elements and maximum value 'k'
void countingSort(int A[], int n, int k) {
    // Create an array C to store the count of each element in A
    int C[k + 1], B[n];

    // Step 1: Initialize the counting array C with zeros
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    // Step 2: Count the occurrences of each element in A and store in C
    for (int i = 0; i < n; i++) {
        C[A[i]] = C[A[i]] + 1;
    }

    // Step 3: Accumulate the counts in C
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    // Step 4: Build the sorted array B
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }

    // Step 5: Copy the sorted array B back to A
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
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

        // Measure the time taken by Counting Sort (averaged over repetitions)
        auto total_duration = chrono::microseconds(0);
        for (int rep = 0; rep < repetitions; rep++) {
            // Create a copy of the original array for each repetition
            int* tempArray = new int[sizes[i]];
            copy(array, array + sizes[i], tempArray);

            auto start_time = chrono::high_resolution_clock::now();
            countingSort(tempArray, sizes[i], 1000); // Provide the maximum value as the third argument
            auto end_time = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            // Release memory allocated for the temporary array
            delete[] tempArray;
        }

        // Print the time taken by Counting Sort for the current array size (averaged over repetitions)
        cout << "Average time taken by Counting Sort for array size " << sizes[i] << ": "
             << total_duration.count() / repetitions << " microseconds\n";

        // Release memory allocated for the original array
        delete[] array;
    }

    return 0;
}
