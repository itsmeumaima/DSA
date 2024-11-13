#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Umaima_Lab10 {
private:
    node* root;
public:
    Umaima_Lab10() : root(nullptr) {}

    void insert(int value) {
        node* newnode = new node(value);
        if (root == nullptr) {
            root = newnode;
            return;
        }
        queue<node*> que;
        que.push(root);
        while (!que.empty()) {
            node* current = que.front();
            que.pop();
            if (current->left == nullptr) {
                current->left = newnode;
                return;
            } else {
                que.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newnode;
                return;
            } else {
                que.push(current->right);
            }
        }
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

    void symmetric() {
        if (root == nullptr) {
            cout << "The tree is symmetric." << endl;
            return;
        }
        if (isSymmetric(root)) {
            cout << "The tree is symmetric." << endl;
        } else {
            cout << "The tree is not symmetric." << endl;
        }
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
        postOrderTraversal(currnode->left);
        postOrderTraversal(currnode->right);
        cout << currnode->data << " ";
    }

    bool isSymmetric(node* root) {
        if (root == nullptr) return true;
        return isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(node* left, node* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->data != right->data) return false;
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
};

int main() {
    Umaima_Lab10 tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(4);
    //tree.insert(3); // Uncomment this line to make the tree symmetric
    tree.symmetric();
    return 0;
}
