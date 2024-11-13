#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int val) :data(val), left(nullptr), right(nullptr) {};
};

class Umaima_Lab10 {
private:
	node* root;
public:
	Umaima_Lab10() :root(nullptr) {};

	void insert(int value) {
		node* newnode = new node(value);
		if (root == nullptr) {
			root = newnode;
			return;
		}
		queue<node*>que;
		que.push(root);
		while (!que.empty()) {
			node* current = que.front();
			que.pop();
			if (current->left == nullptr) {
				current->left = newnode;
				return;
			}
			else {
				que.push(current->left);
			}

			if (current->right == nullptr) {
				current->right= newnode;
				return;
			}
			else {
				que.push(current->right);
			}
		}
	}
	void preOrder() {
		cout << "The pre order Traversal is:"<<endl;
		preOrderTraversal(root);
		cout << endl;
	}
	
	void postOrder() {
		cout << "The post order Traversal is:" << endl;
		postOrderTraversal(root);
		cout << endl;
	}
private:
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
	Umaima_Lab10 tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.preOrder();
	tree.postOrder();
	return 0;
}
