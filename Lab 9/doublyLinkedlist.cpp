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
	node* head;
public:
	Linkedlist() :head(nullptr) {};
	void insertfront(int val) {
		node* newnode = new node(val);
		newnode->next = head;
		newnode->prev = nullptr;
		if (head != nullptr) {
			head->prev = newnode;
		}
		head = newnode;
	}
	void insertlast(int val) {
		node* newnode = new node(val);
		newnode->next = nullptr;
		if (head == nullptr) {
			head = newnode;
			newnode->prev = nullptr;
		}
		else {
			node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev = temp;
		}
	}
	void display() {
		if (head == nullptr) {
			cout << "Empty\n";
			return;
		}
		cout << "List is \n";
		node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void deletenode(int val) {
		if (head == nullptr) {  // Step 1: Check if the list is empty
			cout << "Empty\n";
			return;
		}

		node* temp = head;

		// Step 2: Check if the node to delete is the head node
		if (head->data == val) {
			head = head->next;  // Update head to the next node
			if (head != nullptr) {
				head->prev = nullptr;  // Update the new head's prev pointer
			}
			delete temp;  // Delete the old head node
			return;
		}

		// Step 3: Traverse the list to find the node to delete
		while (temp != nullptr && temp->data != val) {
			temp = temp->next;
		}

		if (temp != nullptr) {  // Node found
			// Update the pointers to bypass the node to be deleted
			if (temp->next != nullptr) {
				temp->next->prev = temp->prev;
			}
			if (temp->prev != nullptr) {
				temp->prev->next = temp->next;
			}
			delete temp;  // Delete the node
		}
		else {
			// Step 4: Value not found
			cout << "Value not found\n";
		}
	}

	
};
int main() {
	Linkedlist l;
	l.insertfront(1);
	l.insertfront(2);
	l.insertfront(4);
	l.insertlast(5);
	l.display();
	l.deletenode(4);
	l.display();
}
