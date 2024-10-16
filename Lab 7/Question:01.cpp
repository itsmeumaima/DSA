#include <iostream>
using namespace std;
class Umaima_Lab07 {
private:
    int capacity;
    int front;
    int rear;
    int* arr;
public:
    Umaima_Lab07(int n) {
        arr = new int[n];
        capacity = n;
        front = -1;
        rear = -1;
    }
    ~Umaima_Lab07() {
        delete[] arr;
    }
    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }
    bool isEmpty() {
        return front == -1;
    }
    void insertFront(int num) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        if (front == -1) { 
            front = 0;
            rear = 0;
        }
        else if (front == 0) {
            front = capacity - 1;
        }
        else {
            front--;
        }
        arr[front] = num;
    }
    void insertLast(int num) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        if (front == -1) { 
            front = 0;
            rear = 0;
        }
        else if (rear == capacity - 1) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = num;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        if (front == rear) { 
            front = rear = -1;
        }
        else if (front == capacity - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void deleteLast() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        if (front == rear) { // Queue has only one element
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = capacity - 1;
        }
        else {
            rear--;
        }
    }
    int getfront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int getrear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "The queue is:" << endl;
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        else {
            for (int i = front; i < capacity; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    Umaima_Lab07 queue(n);
    queue.insertLast(1);
    queue.insertLast(2);
    queue.insertFront(3);
    queue.insertFront(4);
    queue.display();
    cout << "Front element: " << queue.getfront() << endl;
    cout << "Rear element: " << queue.getrear() << endl;
    queue.deleteLast();
    queue.insertFront(4);
    queue.display();
    return 0;
}
