#include <iostream>
using namespace std;
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}
int main() {
    int no, target;
    cout << "Enter number of elements: ";
    cin >> no;
    int* arr = new int[no]; // Dynamically allocate array
    cout << "Enter data for array:" << endl;
    for (int i = 0; i < no; i++) {
        cout << "Enter element: ";
        cin >> arr[i];
    }
    cout << "Enter the target value: ";
    cin >> target;
    int result = binary_search(arr, no, target);
    if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }
    delete[] arr;
    return 0;
}
