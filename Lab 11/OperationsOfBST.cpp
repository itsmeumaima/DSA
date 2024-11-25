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
	int preorder(node* head) {
		if (head == nullptr) {
			return 0;
		}
		int total = head->data;
		total+=preorder(head->left);
		total+=preorder(head->right);
		return total;

	}
	void postorder(node* head) {
		if (head == nullptr) {
			return;
		}
		postorder(head->left);
		postorder(head->right);
		cout << head->data << " ";
	}
	/*node* insert(node* curr, int val) {
		if (curr == nullptr) {
			return new node(val);
		}
		if (val < curr->data) {
			curr->left = insert(curr->left, val);
		}
		else if (val > curr->data) {
			curr->right = insert(curr->right, val);
		}
		return curr;
	}*/
	void insert(node*& curr, int val) {
		node* newNode = new node(val);
		if (curr == nullptr) {
			curr = newNode;
			return;
		}

		node* temp = curr;
		node* parent = nullptr;

		while (temp != nullptr) {
			parent = temp;
			if (temp->data > val) {
				temp = temp->left;
			}
			else if (temp->data < val) {
				temp = temp->right;
			}
			else {
				// Value already exists in the tree
				delete newNode;
				return;
			}
		}

		if (parent->data > val) {
			parent->left = newNode;
		}
		else {
			parent->right = newNode;
		}
	}
	node* leastCA(node* head, int n1, int n2) {
		if (head == nullptr) {
			return nullptr;
		}
		if (head->data > n1 && head->data > n2) {
			return leastCA(head->left, n1, n2);
		}
		if (head->data < n1 && head->data < n2) {
			return leastCA(head->right, n1, n2);
		}
		return head;
	}
	node* deletenode(node* curr, int val) {
		if (curr == nullptr) return curr;

		// Traverse the tree to find the node to delete
		if (curr->data > val) {
			curr->left = deletenode(curr->left, val);
		}
		else if (curr->data < val) {
			curr->right = deletenode(curr->right, val);
		}
		else {
			// Node to be deleted is found

			// Case 1: Node has only one child or no child
			if (curr->left == nullptr) {
				node* temp = curr->right;
				delete curr;
				return temp;
			}
			else if (curr->right == nullptr) {
				node* temp = curr->left;
				delete curr;
				return temp;
			}

			// Case 2: Node has two children
			// Find the inorder successor (smallest in the right subtree)
			node* temp = minvalue(curr->right);
			// Copy the inorder successor's data to the current node
			curr->data = temp->data;
			// Delete the inorder successor
			curr->right = deletenode(curr->right, temp->data);
		}
		return curr;
	}
public:
	tree() :root(nullptr) {};
	void insertnode(int val) {
		insert(root, val);
	}
	void CA(int n1, int n2) {
		node* temp= leastCA(root, n1, n2);
		if (temp != nullptr) {
			cout << "The least common ancestor is :" << temp->data;
		}
		else {
			cout << "No least common ancestor\n";
		}
	}
	void inordertravesal() {
		if (root == nullptr) return;
		cout << "The list is\n";
		inorder(root);
	}
	/*void preordertravesal() {
		if (root == nullptr) return;
		cout << "The list is\n";
		preorder(root);
	}*/
	void postordertravesal() {
		if (root == nullptr) return;
		cout << "The list is\n";
		postorder(root);
	}
	void search(int val) {
		bool ans = false;
		node* temp = root;
		while (temp != nullptr) {
			if (temp->data == val) {
				ans = true;
				break;
			}
			else if (temp->data > val) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		if (ans) {
			cout << "Value found\n";
		}
		else {
			cout << "value not found\n";
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
	void sum() {
		//int total=0;
		cout<<"The sum is :"<<preorder(root);
	}
	node* minvalue(node* head) {
		node* curr = head;
		// Loop to find the leftmost (smallest) node
		while (curr != nullptr && curr->left != nullptr) {
			curr = curr->left;
		}
		return curr;
	}
	void Delete(int val) {
		root=deletenode(root, val);
	}
};
int main() {
	tree t;
	t.insertnode(5);
	t.insertnode(2);
	t.insertnode(6);
	t.insertnode(3);
	t.insertnode(1);
	t.breathtraversal();
	t.sum(); cout << endl;
	t.CA(1, 6);
	cout << endl;
	t.search(8);
	t.Delete(2);
	t.breathtraversal();

}
