#include <iostream>
#include <stack>
using namespace std;

class quicksort {
    int* arr;
    int n;
public:
    quicksort(int no) {
        n = no;
        arr = new int[n];
    }
    ~quicksort() {
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
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int partition(int low, int high) {
        int pivot = arr[low];  // Starting element as pivot
        int i = low + 1;
        for (int j = low + 1; j <= high; j++) {
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[low], arr[i - 1]);
        return (i - 1);
    }
    void sort() {
        stack<int> s;
        s.push(0);
        s.push(n - 1);
        while (!s.empty()) {
            int high = s.top();
            s.pop();
            int low = s.top();
            s.pop();
            int pivotIndex = partition(low, high);
            if (pivotIndex - 1 > low) {
                s.push(low);
                s.push(pivotIndex - 1);
            }
            if (pivotIndex + 1 < high) {
                s.push(pivotIndex + 1);
                s.push(high);
            }
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    quicksort qs(size);
    qs.input();
    qs.sort();
    qs.display();
    return 0;
}
