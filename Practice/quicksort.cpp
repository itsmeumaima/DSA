#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(int arr[], int p, int r) {
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] < pivot) {
            i += 1;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[r]); // Move pivot to the correct place
    return i + 1;
}

// QuickSort function
void quicksort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1); // Recursively sort the left part
        quicksort(arr, q + 1, r); // Recursively sort the right part
    }
}

int main() {
    int arr[7] = { 12, 3, 76, 21, 1, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1); // Note that the array size is n-1 for the high index
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
