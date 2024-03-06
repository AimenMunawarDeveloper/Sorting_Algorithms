#include <iostream>
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