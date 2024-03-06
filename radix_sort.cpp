#include<iostream>
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