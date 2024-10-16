#include <iostream>
using namespace std;
class Umaima_Lab07 {
    int* arr;
    int rear;
    int front;
    int capacity;
    int count;
public:
    Umaima_Lab07(int n) {
        capacity = n;
        arr = new int[n];
        front = 0;
        rear = n - 1;
        count = n;
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
    }
    bool isEmpty() {
        return count == 0;
    }
    
    void findwinner(int k) {
        while (count > 1) {
            front = (front + k - 1) % count; 
            for (int i = front; i < count - 1; i++) { 
                arr[i] = arr[i + 1];
            }
            count -= 1; 
        }
        cout << "The winner is: " << arr[0] << endl;
    }
};

int main() {
    int n, k;
    cout << "Enter the number of friends: ";
    cin >> n;
    cout << "Enter the key: ";
    cin >> k;
    Umaima_Lab07 queue(n);
    queue.findwinner(k);

    return 0;
}
