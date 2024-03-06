#include<iostream>
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