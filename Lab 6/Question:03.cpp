#include <iostream>
using namespace std;
class Umaima_Lab06 {
private:
    int capacity;
    int front;
    int rear;
    int* arr;
public:
    Umaima_Lab06(int n) {
        arr = new int[n];
        capacity = n;
        front = -1;
        rear = -1;
    }
    ~Umaima_Lab06() {
        delete[] arr;
    }
    bool isFull() {
        return front == 0 && rear == capacity - 1;
    }
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    void insertFront(int num) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        arr[--front] = num;
    }
    void insertRear(int num) {
        if (isFull()) {
            cout << "Queue is full.";
            return;
        }
        arr[++rear] = num;
        if (front == -1) front++;
    }
    void deleteFront() {
        if(isEmpty()) {
            cout << "Queue is empty";
            return ;
        }
        int data = arr[front];
        front++;
    }
    void deleteRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int data = arr[rear];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            rear--;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "The queue is:" << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
    int size() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return (rear - front + 1);
    }
};
int main() {
    int n;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    Umaima_Lab06 queue(n);
    queue.insertRear(1);
    queue.insertRear(2);
    queue.insertFront(3);
    queue.insertFront(4);
    queue.display();
    cout << "Size of the queue: " << queue.size() << endl;
    queue.deleteFront();
    queue.display();
    queue.deleteRear();
    queue.display();
    cout << "Size of the queue: " << queue.size() << endl;
    return 0;
}
