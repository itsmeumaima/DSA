#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int val) :data(val), next(nullptr) {};
};
class Linkedlist {
	node* head;
public:
	Linkedlist() :head(nullptr) {};
	void insert(int val) {
		node* newnode = new node(val);
		if (head == nullptr) {
			head = newnode;
		}
		else {
			node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
	void insertpos(int pos, int val) {
		node* newnode = new node(val);
		if (pos == 0) {
			newnode->next = head;
			head = newnode;
		}
		else {
			int position = 0;
			node* prev = nullptr;
			node* curr = head;
			while (curr != nullptr && position < pos) {
				prev = curr;
				curr = curr->next;
				position++;
			}
			if (curr == nullptr and position < pos) {
				prev->next = newnode;
			}
			else {
				prev->next = newnode;
				newnode->next = curr;
			}
		}
	}
	void deletenode(int key) {
		if (head == nullptr) return;
		node* temp = head;
		node* prev = nullptr;
		if (temp->data == key) {
			head = temp->next;
			delete temp;
		}
		else {
			while (temp != nullptr && temp->data != key) {
				prev = temp;
				temp = temp->next;
			}
			if (temp == nullptr) return;
			prev->next = temp->next;
			delete temp;
		}
	}
	void display() {
		if (head == nullptr) {
			cout << "List is empty\n";
			return;
		}
		node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	bool search(int val) {
		node* temp = head;
		while (temp != nullptr) {
			if (temp->data == val) return true;
			else {
				temp = temp->next;
			}
		}
	}
	bool palindrome() {
		if (!head || !head->next) {
			return true;
		}
		node* slow = head;
		node* fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		node* prev = nullptr;
		node* curr = slow;
		while (curr) {
			node* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		// Step 3: Compare the first half and the reversed second half
		node* firsthalf = head;
		node* secondhalf = prev;
		while (secondhalf) {
			if (firsthalf->data != secondhalf->data) {
				return false;
			}
			firsthalf = firsthalf->next;
			secondhalf = secondhalf->next;
		}
		return true;
	}
};
int main() {
	Linkedlist l;
	l.insert(2);
	l.insert(5);
	l.insert(6);
	l.insert(5);
	l.insert(2);
	l.display();
	cout << endl;
	l.insertpos(3, 6);
	l.display();
	cout<<"\n The list is palindrome:"<<l.palindrome();
}
