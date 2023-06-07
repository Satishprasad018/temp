#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to merge two subarrays of arr[]
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int size = 100000;
    int arr[size];

    // Best case scenario: Sorted array
    generateRandomArray(arr, size);
    //cout << "Original Array: ";
   // printArray(arr, size);

    // Best Case: Already sorted array
    cout << "Best Case:" << endl;
    clock_t start = clock();
    mergeSort(arr, 0, size - 1);
    clock_t end = clock();
    double bestCaseTime = double(end - start) / CLOCKS_PER_SEC;
   // cout << "Sorted Array: ";
    //printArray(arr, size);
    cout << "Time taken: " << bestCaseTime << " seconds" << endl;

    // Worst Case: Array sorted in reverse order
    cout << "Worst Case:" << endl;
    for (int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size - i - 1]);
    start = clock();
    mergeSort(arr, 0, size - 1);
    end = clock();
    double worstCaseTime = double(end - start) / CLOCKS_PER_SEC;
    //cout << "Sorted Array: ";
  // printArray(arr, size);
    cout << "Time taken: " << worstCaseTime << " seconds" << endl;

    /* Average Case: Randomly shuffled array
    cout << "Average Case:" << endl;
    random_shuffle(arr, arr + size);
    start = clock();
    mergeSort(arr, 0, size - 1);
    end = clock();
    double averageCaseTime = double(end - start) / CLOCKS_PER_SEC;
    cout << "Sorted Array: ";
    printArray(arr, size);
    cout << "Time taken: " << averageCaseTime << " seconds" << endl;
*/
    return 0;
}
