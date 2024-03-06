#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Bucket Sort algorithm for sorting an array of floating-point numbers
void bucketSort(float A[], int n) {
    // Create an array of vectors to represent buckets
    vector<float> bucket[n];

    // Distribute elements into buckets based on their values
    for (int i = 0; i < n; i++) {
        // Calculate the index of the bucket for the current element
        int bucketIndex = A[i] * n;
        
        // Add the element to the corresponding bucket
        bucket[bucketIndex].push_back(A[i]);
    }

    // Sort each bucket individually using the standard sorting algorithm
    for (int i = 0; i < n; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    // Concatenate sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            A[index++] = bucket[i][j];
        }
    }
}

int main() {
    // Example array of floating-point numbers
    float array[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(array) / sizeof(array[0]);
    
    // Display the unsorted array
    cout << "Array before Sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    // Call the bucketSort function to sort the array
    bucketSort(array, n);

    // Display the sorted array
    cout << "\nArray After Sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
