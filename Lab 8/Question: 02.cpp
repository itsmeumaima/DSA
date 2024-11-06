//1. Implement class of a Circular Queue using a Linked List.
#include <iostream>
using namespace std;

class Umaima_Lab08 {
private:
	struct Node {
		int data;
		Node* next;
		Node(int val) : data(val), next(nullptr) {}
	};
	Node* top;
public:
	Umaima_Lab08() : top(nullptr) {}

	bool isEmpty() {
		return top == nullptr;
	}
	void push(int data) {
		Node* newNode = new Node(data);
		newNode->next = top;
		top = newNode;
	}

	void pop() {

		if (isEmpty()) {
			cout<<"Stack is empty\n";
			return;
		}
		Node* temp = top;
		top = top -> next;
		delete temp;
	}
	void display() {
		if (isEmpty()) {
			cout<<"Stack is empty\n"<<" ";
			return;
		}

		Node* temp = top;
		while (temp != nullptr) {
			cout<<temp -> data<<" ";
			temp = temp -> next;
		}
		cout<< endl;
	}
};
int main() {
	Umaima_Lab08 stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.pop();
	stack.display();	
	return 0;
}
