#include <iostream>
using namespace std;
class Umaima_Lab04 {
    int n;
    int *arr;
public:
    Umaima_Lab04(int no) {
        n = no;
        arr = new int[n];
    }
    void inputArray() {
        cout << "Enter the elements of the array:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    void bubblesort() {
        for (int i = 0; i < n - 1; i++) {
            bool ans = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    ans = true;
                    swap(arr[j], arr[j + 1]);
                }
            }
            if (!ans) {
                break;
            }
        }
    }
    void display() {
        cout << "The sorted array is:" << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Umaima_Lab04() {
        delete[] arr;
    }
};
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    Umaima_Lab04 sort(n);
    sort.inputArray();
    sort.bubblesort();
    sort.display();
    return 0;
}
