#include <iostream>
using namespace std;
class Umaima_Lab06 {
private:
    int capacity;
    int front;
    int rear;
    int count;
    int* arr;
public:
    Umaima_Lab06(int n) {
        arr = new int[n];
        capacity = n;
        front = -1;
        rear = -1;
        count = 0;
    }
    ~Umaima_Lab06() {
        delete[] arr;
    }
    void display() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "The queue is: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
    void enqueue(int num) {
        if (full()) {
            cout << "Circular Queue is full." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = num;
        count++;
        if (front == -1) {
            front = 0;
        }
    }
    void dequeue() {
        if (empty()) {
            cout << "Circular Queue is empty." << endl;
            return;
        }
        front = (front + 1) % capacity;
        count--;
        if (count == 0) {
            front = -1;
            rear = -1;
        }
    }
    void front_element() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "The front element of queue is: " << arr[front] << endl;
    }
    void rear_element() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "The rear element of queue is: " << arr[rear] << endl;
    }
    bool full() {
        return count == capacity;
    }
    bool empty() {
        return count == 0;
    }
    void size() {
        cout << "The size of queue is: " << count << endl;
    }
};
int main() {
    int n;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    Umaima_Lab06 queue(n);
    queue.enqueue(10);
    queue.enqueue(3);
    queue.enqueue(9);
    queue.display();
    queue.dequeue();
    queue.display();
    queue.front_element();
    queue.rear_element();
    queue.size();
    return 0;
}
