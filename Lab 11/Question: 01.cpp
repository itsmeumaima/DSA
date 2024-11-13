#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int val) :data(val), left(nullptr), right(nullptr) {};
};

class Umaima_Lab11 {
private:
	node* root;
public:
	Umaima_Lab11() :root(nullptr) {};

	void insertrec(int val) {
		root = insert(root, val);
	}
	void preOrder() {
		cout << "The pre order Traversal is:" << endl;
		preOrderTraversal(root);
		cout << endl;
	}

	void postOrder() {
		cout << "The post order Traversal is:" << endl;
		postOrderTraversal(root);
		cout << endl;
	}
private:
	node* insert(node* root, int value) {
		node* newnode = new node(value);
		if (root == nullptr) {
			return new node(value);
			
		}
		if (value < root->data) {
			root->left = insert(root->left, value);
		}
		else if (value > root->data) {
			root->right = insert(root->right, value);
		}
		return root;
	}
	void preOrderTraversal(node* currnode) {
		if (currnode == nullptr) {
			return;
		}
		cout << currnode->data << " ";
		preOrderTraversal(currnode->left);
		preOrderTraversal(currnode->right);
	}
	void postOrderTraversal(node* currnode) {
		if (currnode == nullptr) {
			return;
		}
		preOrderTraversal(currnode->left);
		preOrderTraversal(currnode->right);
		cout << currnode->data << " ";
	}
};
int main() {
	Umaima_Lab11 BST;
	BST.insertrec(50);
	BST.insertrec(30);
	BST.insertrec(20);
	BST.insertrec(40);
	BST.insertrec(70);
	BST.postOrder();
	BST.preOrder();
	return 0;
}
