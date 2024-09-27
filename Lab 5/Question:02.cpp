#include <iostream>
using namespace std;

class mergesort {
    int* arr;
    int n;
    int result[50];
public:
    mergesort(int no) {
        n = no;
        arr = new int[n];
    }
    ~mergesort() {
        delete[] arr;
    }
    void input() {
        cout << "Enter data for array :" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Enter data: ";
            cin >> arr[i];
        }
    }
    void display() {
        cout << "The sorted array is: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void merge(int lower, int mid, int high) {
        int i = lower;
        int j = mid + 1;
        int k = lower;

        while (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                result[k] = arr[i];
                i++;
            }
            else {
                result[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {
            result[k] = arr[i];
            i++;
            k++;
        }
        while (j <= high) {
            result[k] = arr[j];
            j++;
            k++;
        }
        for (int l = lower; l <= high; l++) {
            arr[l] = result[l];
        }
    }
    void sorting() {
        for (int i = 1; i < n; i *= 2) {
            for (int j = 0; j < n; j += 2 * i) {
                int mid = j + i - 1;
                if (mid >= n) {
                    mid = n - 1;
                }
                int right = j + 2 * i - 1;
                if (right >= n) {
                    right = n - 1;
                }
                if (mid < right) {
                    merge(j, mid, right);
                }
            }
        }
    }
};

int main() {
    mergesort m(6);
    m.input();
    m.sorting();
    m.display();

    return 0;
}
