#include<iostream>
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
