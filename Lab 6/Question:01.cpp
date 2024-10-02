#include <iostream>
using namespace std;

class Umaima_Lab06 {
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
	void display() {
		cout << "The queue is :" << endl;
		for (int i = front; i <= rear; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void resize() {
		int* temp = new int[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		capacity = capacity * 2;
	}
	void enqueue(int num) {
		if (rear == capacity) {
			cout << "Queue id full." << endl;
		}
		rear += 1;
		arr[rear] = num;
		if (front == -1) {
			front += 1;
		}
	}
	bool empty() {
		return rear == front;
	}
	void dequeue() {
		if (empty()) {
			cout << "Queue is empty." << endl;
		}
		int data = arr[front];
		front++;
	}
};
int main() {
	int n;
	cout << "Enter the number of elements in the queue:";
	cin >> n;
	Umaima_Lab06 queue(n);
	queue.enqueue(10);
	queue.enqueue(3);
	queue.enqueue(9);
	queue.display();
	queue.dequeue();
	queue.display();
	return 0;
}
