//1. Implement class of a Circular Queue using a Linked List.
#include <iostream>
using namespace std;

class Umaima_Lab08 {
	struct Node{
		int data;
		Node* next;
		Node(int val) :data(val), next(nullptr) {};
	};
	Node* front;
	Node* rear;
public:
	Umaima_Lab08() :front(nullptr), rear(nullptr) {};

	bool isempty() {
		return front == nullptr;
	}
	void enqueue(int value) {
		Node* newnode = new Node(value);
		if (isempty()) {
			front = rear = newnode;
			rear->next = front;
		}
		else {
			rear -> next = newnode;
			rear = newnode;
			rear -> next = front;
		}
	}
	void dequeue() {
		if (isempty()) {
			cout << "Queue is empty\n";
			return;
		}
		if (front == rear) {
			delete front;
			front = rear = nullptr;
		}
		else {
			Node* temp = front;
			front = front->next;
			rear->next = front;
			delete temp;
			}
		}
		void display() {
			if (isempty()) {
				cout << "List is empty.";
				return;
			}
			Node* temp = front;
			do {
				cout<< temp -> data<<" ";
				temp = temp -> next;
			} while (temp != front);
		}
};

int main() {
	Umaima_Lab08 linked_list;
	linked_list.enqueue(2);
	linked_list.enqueue(3);
	linked_list.display();
	linked_list.dequeue();
	linked_list.display();
	
	return 0;
}
