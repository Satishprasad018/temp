#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to generate an array with random elements
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to display an array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 10000;
    int arr[SIZE];

    // Best case scenario: Sorted array
    generateRandomArray(arr, SIZE);
    quickSort(arr, 0, SIZE - 1);
    cout << "Best Case (Sorted Array): " << endl;

    // Measure time taken for best case scenario
    clock_t startBest = clock();
    quickSort(arr, 0, SIZE - 1);
    clock_t endBest = clock();

    cout << "Time taken for Best Case: " << (double)(endBest - startBest) / CLOCKS_PER_SEC << " seconds" << endl;

    // Average case scenario: Random array
    generateRandomArray(arr, SIZE);
    cout << "Average Case (Random Array): " << endl;

    // Measure time taken for average case scenario
    clock_t startAvg = clock();
    quickSort(arr, 0, SIZE - 1);
    clock_t endAvg = clock();

    cout << "Time taken for Average Case: " << (double)(endAvg - startAvg) / CLOCKS_PER_SEC << " seconds" << endl;

    // Worst case scenario: Reverse sorted array
    for (int i = 0; i < SIZE / 2; i++) {
        swap(arr[i], arr[SIZE - i - 1]);
    }
    cout << "Worst Case (Reverse Sorted Array): " << endl;

    // Measure time taken for worst case scenario
    clock_t startWorst = clock();
    quickSort(arr, 0, SIZE - 1);
    clock_t endWorst = clock();

    cout << "Time taken for Worst Case: " << (double)(endWorst - startWorst) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
