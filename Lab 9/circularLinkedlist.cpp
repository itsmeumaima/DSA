#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int val) :data(val), next(nullptr) {};
};
class Linkedlist {
	node* tail;
public:
	Linkedlist() :tail(nullptr) {};
	void enqueue(int val) {
		node* newnode = new node(val);
		if (!tail) {
			tail = newnode;
			tail->next = tail;
		}
		else {
			newnode->next = tail->next;
			tail->next = newnode;
			tail = newnode;
		}
	}
	void dequeue() {
		if (tail == nullptr) {
			cout << "Empty--\n";
			return;
		}
		node* temp = tail->next;
		if (tail->next == tail) {
			delete tail;
			tail = nullptr;
		}
		else {
			tail->next = tail->next->next;
			delete temp;
		}
	}
	void insertend(int val) {
		node* newnode = new node(val);
		if (tail == nullptr) {
			tail = newnode;
			tail->next = tail;
		}
		else {
			newnode->next = tail->next;
			tail->next = newnode;
			tail = newnode;
		}
	}
	void insertfront(int val) {
		node* newnode = new node(val);
		if (tail == nullptr) {
			tail = newnode;
			tail->next = tail;
		}
		else {
			newnode->next = tail->next;
			tail->next = newnode;
		}
	}
	void deletenode(int key) {
		if (tail == nullptr) {
			cout << "Empty\n";
			return;
		}

		node* temp = tail->next;
		node* prev = tail;

		// Check if the only node in the list is the one to be deleted
		if (tail == tail->next && tail->data == key) {
			delete tail;
			tail = nullptr;
			return;
		}

		// Check if the node to delete is the first node (next of tail)
		if (temp->data == key) {
			prev->next = temp->next;
			delete temp;
			return;
		}

		// Traverse the list to find the node to delete
		do {
			prev = temp;
			temp = temp->next;

			if (temp->data == key) {
				prev->next = temp->next;
				if (temp == tail) {
					tail = prev;
				}
				delete temp;
				return;
			}
		} while (temp != tail->next);

		// If we reach here, the node was not found
		cout << "No value found.\n";
	}

	void display() {
		if (tail == nullptr) {
			cout << "Empty--\n";
			return;
		}
		cout << "List is \n";
		node* temp = tail->next;
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != tail->next);
		cout << endl;
	}
	
};
int main() {
	Linkedlist l;
	l.insertfront(1);
	l.insertfront(3);
	l.insertfront(4);
	l.display();
	l.insertend(2);
	l.display();
	l.deletenode(3);
	l.display();
}
