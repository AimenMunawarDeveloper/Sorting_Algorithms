#include <iostream>
#include <cmath>
#include <chrono>
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
    for (int i = floor(n / 2) - 1; i >= 0; i--) { // Adjusted loop condition
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

            // Measure the time taken by heap Sort
            auto start_time = chrono::high_resolution_clock::now();
            heapSort(array, sizes[i]);
            auto end_time = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            // Release memory allocated for the array
            delete[] array;
        }

        // Calculate the average time taken by Heap Sort for the current array size
        auto average_duration = total_duration.count() / repetitions;

        // Print the results
        cout << "Average time taken by Heap Sort for array size " << sizes[i] << ": "
             << average_duration << " microseconds\n\n";
    }

    return 0;
}
