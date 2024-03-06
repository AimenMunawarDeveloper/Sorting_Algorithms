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
