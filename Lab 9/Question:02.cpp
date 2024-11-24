#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* prev;
	node* next;
	node(int val) :data(val), prev(nullptr), next(nullptr) {};
};
class Linkedlist {
	node* front;
	node* rear;
public:
	Linkedlist() :front(nullptr),rear(nullptr){};
	void insertfront(int val) {
		node* newnode = new node(val);
		if (front == nullptr) {
			front = rear = newnode;
		}
		else {
			newnode->prev = nullptr;
			newnode->next = front;
			front->prev = newnode;
			front = newnode;
		}
	}
	void insertrear(int val) {
		node* newnode = new node(val);
		if (rear == nullptr) {
			front = rear = newnode;
		}
		else {
			rear->next = newnode;
			newnode->next = nullptr;
			newnode->prev = rear;
			rear = newnode;
		}
	}
	void display() {
		node* temp = front;
		cout << "list is\n";
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void deletefront() {
		if (front == nullptr) {
			cout << "Empty\n";
			return;
		}
		node* temp = front;
		if (front == rear) {
			front = rear = nullptr;
		}
		else {
			front = front->next;
			front->prev = nullptr;
		}		
	}
	void deleterear() {
		if (rear == nullptr) {
			cout<< "Empty\n";
			return;
		}
		node* temp = front;
		if (front == rear) {
			front = rear = nullptr;
		}
		else {
			rear = rear->prev;
			rear->next = nullptr;
		}
	}
};
int main() {
	Linkedlist l;
	l.insertfront(1);
	l.insertfront(0);
	l.insertrear(2);
	l.insertrear(3);
	l.display();
	l.deletefront();
	l.display();
	l.insertfront(5);
	l.deleterear();
	l.display();
}
