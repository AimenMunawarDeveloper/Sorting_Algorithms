#include <iostream>
#include <cmath>
using namespace std;

// Function to get the index of the left child of node i in a heap
int left_child(int i) {
    return 2 * i + 1; // Adjusted for zero-based indexing
}

// Function to get the index of the right child of node i in a heap
int right_child(int i) {
    return 2 * i + 2; // Adjusted for zero-based indexing
}

// Function to maintain the max-heap property, assuming left and right subtrees are max-heaps
void max_heapify(int A[], int i, int n) {
    int l = left_child(i);
    int r = right_child(i);
    int largest = i;

    // Compare the left child with the current node
    if (l < n && A[l] > A[largest]) {
        largest = l;
    }

    // Compare the right child with the current node
    if (r < n && A[r] > A[largest]) {
        largest = r;
    }

    // If the largest is not the current node, swap the current node with the largest child
    if (largest != i) {
        swap(A[i], A[largest]);

        // Recursively call max_heapify on the affected subtree
        max_heapify(A, largest, n);
    }
}

// Function to build a max heap from an array
void build_max_heap(int A[], int n) {
    for (int i = floor(n/2) - 1; i >= 0; i--) { // Adjusted loop condition
        max_heapify(A, i, n);
    }
}

// Function to perform Heap Sort
void heapSort(int A[], int n) {
    // Build max heap from the given array
    build_max_heap(A, n);

    // Perform Heap Sort
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (maximum element) with the last element
        swap(A[0], A[i]);

        // Re-heapify the reduced heap (exclude the last element)
        max_heapify(A, 0, i);
    }
}