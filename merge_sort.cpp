#include<iostream>
#include<climits> // Include this header for INT_MAX
using namespace std;

// Merge function to merge two sorted subarrays A[p..q] and A[q+1..r]
void merge(int A[], int p, int q, int r) {
    // Calculate the sizes of the two subarrays
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create temporary arrays to hold the two subarrays
    int L[n1 + 1], R[n2 + 1];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + j + 1];
    }

    // Set the sentinels at the end of each array
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    // Merge the two sorted subarrays back into the original array A[p..r]
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

// MergeSort function to recursively sort the array A[p..r]
void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; // Calculate the midpoint of the array

        // Recursively sort the two halves
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);

        // Merge the sorted halves
        merge(A, p, q, r);
    }
}