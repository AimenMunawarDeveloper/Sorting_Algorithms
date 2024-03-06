#include <iostream>
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

