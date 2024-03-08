#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>

using namespace std;

// Bucket Sort algorithm for sorting an array of floating-point numbers in the range [0,1)
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
    // Array sizes to test
    const int sizes[] = {10, 100, 1000, 10000};

    // Number of repetitions for each array size
    const int repetitions = 100;

    // Loop through the array sizes
    for (int i = 0; i < 4; i++) {
        // Create a dynamic array of the current size
        float* array = new float[sizes[i]];

        // Initialize array with random values in the range [0,1)
        for (int j = 0; j < sizes[i]; j++) {
            array[j] = static_cast<float>(rand()) / RAND_MAX;
        }

        // Measure the time taken by Bucket Sort (averaged over repetitions)
        auto total_duration = chrono::microseconds(0);
        for (int rep = 0; rep < repetitions; rep++) {
            // Create a copy of the original array for each repetition
            float* tempArray = new float[sizes[i]];
            copy(array, array + sizes[i], tempArray);

            auto start_time = chrono::high_resolution_clock::now();
            bucketSort(tempArray, sizes[i]);
            auto end_time = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            // Release memory allocated for the temporary array
            delete[] tempArray;
        }

        // Print the time taken by Bucket Sort for the current array size (averaged over repetitions)
        cout << "Average time taken by Bucket Sort for array size " << sizes[i] << ": "
             << total_duration.count() / repetitions << " microseconds\n";

        // Release memory allocated for the original array
        delete[] array;
    }

    return 0;
}
