#include<iostream>
#include<chrono>
using namespace std;

// Function to partition the array A[p..r] and return the pivot index
int partition(int A[], int p, int r) {
    // Choose the pivot element (in this case, the rightmost element)
    int x = A[r];
    int i = p - 1;

    // Iterate through the subarray A[p..r-1]
    for (int j = p; j <= r - 1; j++) {
        // If the current element is less than or equal to the pivot
        if (A[j] <= x) {
            // Increment the index of the smaller element
            i++;

            // Swap A[i] and A[j]
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // Swap A[i+1] and the pivot (A[r])
    int temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    // Return the index of the pivot element after partitioning
    return i + 1;
}

// Function to perform QuickSort on array A[p..r]
void quickSort(int A[], int p, int r) {
    // If there are more than one element in the subarray
    if (p < r) {
        // Partition the array and get the pivot index
        int q = partition(A, p, r);

        // Recursively sort the subarrays before and after the pivot
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
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

            // Measure the time taken by QuickSort
            auto start_time = chrono::high_resolution_clock::now();
            quickSort(array, 0, sizes[i] - 1);
            auto end_time = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            // Release memory allocated for the array
            delete[] array;
        }

        // Calculate the average time taken by QuickSort for the current array size
        auto average_duration = total_duration.count() / repetitions;

        // Print the results
        cout << "Average time taken by QuickSort for array size " << sizes[i] << ": "
             << average_duration << " microseconds\n\n";
    }

    return 0;
}