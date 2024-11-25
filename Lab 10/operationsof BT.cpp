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
class tree {
	node* root;
	void inorder(node* head) {
		if (head == nullptr) {
			return;
		}
		inorder(head->left);
		cout << head->data << " ";
		inorder(head->right);
	}
	void preorder(node* head) {
		if (head == nullptr) {
			return;
		}
		cout << head->data << " ";
		preorder(head->left);
		preorder(head->right);
	}
	void postorder(node* head) {
		if (head == nullptr) {
			return;
		}
		postorder(head->left);
		postorder(head->right);
		cout << head->data << " ";
	}
	bool searchnode(node* head,int val) {
		if (head == nullptr) return false;
		if (head->data == val) return true;
		bool leftsearch = searchnode(head->left, val);
		if (leftsearch) return true;
		return searchnode(head->right, val);
	}
	bool issymmetric(node* head) {
		if (head == nullptr) return true;
		return issymmetrical(head->left, head->right);
	}
	bool issymmetrical(node* left, node* right) {
		if (left == nullptr && right == nullptr) return true;
		if (left == nullptr || right == nullptr) return false;
		if (left->data != right->data) return false;
		return issymmetrical(left->left, right->right) && issymmetrical(left->right, right->left);
	}
public:
	tree() :root(nullptr) {};
	void insert(int val) {
		node* newnode = new node(val);
		if (root == nullptr) {
			root = newnode;
			return;
		}
		else {
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
					current->right = newnode;
					return;
				}
				else {
					que.push(current->right);
				}
			}
		}
	}
	void inordertravesal() {
		if (root == nullptr) return;
		cout << "The list is\n";
		inorder(root);
	}
	void preordertravesal() {
		if (root == nullptr) return;
		cout << "The list is\n";
		preorder(root);
	}
	void postordertravesal() {
		if (root == nullptr) return;
		cout << "The list is\n";
		postorder(root);
	}
	bool search(int val) {
		return searchnode(root, val);
	}
	void symmetric() {
		if (root == nullptr) {
			return;
		}
		if (issymmetric(root)) {
			cout << "The tree is symmetric\n";
		}
		else {
			cout << "The tree is not symmetric\n";
		}
	}
	void breathtraversal() {
		if (root == nullptr) return;
		queue<node*> que;
		que.push(root);
		while (!que.empty()) {
			node* curr = que.front();
			que.pop();
			cout << curr->data << " ";
			if (curr->left != nullptr) que.push(curr->left);
			if (curr->right != nullptr) que.push(curr->right);
		}
	}
	void deleteNode(int key) {
		if (root == nullptr) {
			cout << "Tree is empty\n";
			return;
		}
		if (root->left == nullptr && root->right == nullptr) {
			if (root->data == key) {
				delete root;
				root = nullptr;
			}
		}
		queue<node*> que;
		que.push(root);
		node* target = nullptr;
		node* last = nullptr;
		node* parent = nullptr;
		while (!que.empty()) {
			last = que.front();
			que.pop();
			if (last->data == key) {
				target = last;
			}
			if (last->left != nullptr) {
				parent = last;
				que.push(last->left);
			}
			if (last->right != nullptr) {
				parent = last;
				que.push(last->right);
			}
		}
		if (target) {
			int lastdata = last->data;
			delete last;
			if (parent->left && parent->left->data==lastdata) {
				parent->left = nullptr;
			}
			else {
				parent->right = nullptr;
			}
			target->data = lastdata;
		}
		else {
			cout << "Node not found\n";
		}
	}
	
};
int main() {
	tree t;
	t.insert(1);
	t.insert(2);
	t.insert(5);
	t.insert(4);
	t.insert(3);
	t.preordertravesal();
	cout << "\nValue found " << t.search(5) << endl;
	t.symmetric();
	cout << "\nThe breath traversal is\n";
	t.breathtraversal();
	t.deleteNode(1);
	cout << "\nThe breath traversal is\n";
	t.breathtraversal();
}
