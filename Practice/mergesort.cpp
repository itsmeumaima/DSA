#include <iostream>
using namespace std;

void merge(int arr[], int p, int mid, int r) {
    int n1 = mid - p + 1;
    int n2 = r - mid;
    int* l=new int[n1];
    int* h = new int[n2];

    for (int i = 0; i < n1; i++) {
        l[i] = arr[i + p];
    }
    for (int i = 0; i < n2; i++) {
        h[i] = arr[i + mid + 1];
    }
    int i = 0;
    int j = 0;
    int k = p;

    while (i < n1 && j < n2) {
        if (l[i] <= h[j]) {
            arr[k] = l[i];
            i++;
        }
        else {
            arr[k] =h[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = h[j];
        j++;
        k++;
    }

    // Clean up memory
    delete[] l;
    delete[] h;
}
void mergesort(int arr[],int p,int r) {
    if (p < r) {
        int mid = p + (r-p) / 2;
        mergesort(arr, p, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, p, mid, r);
    }
}

int main() {
    int arr[7] = { 12, 3, 76, 21, 1, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, n - 1);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
