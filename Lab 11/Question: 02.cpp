#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Umaima_Lab11 {
private:
    node* root;
public:
    Umaima_Lab11() : root(nullptr) {}

    void insertrec(int val) {
        root = insert(root, val);
    }
    node* findLCA(int n1, int n2) {
        return findLCA(root, n1, n2);
    }

private:
    node* insert(node* root, int value) {
        if (root == nullptr) {
            return new node(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }
        return root;
    }
    node* findLCA(node* currnode, int n1, int n2) {
        if (currnode == nullptr) {
            return nullptr;
        }
        if (currnode->data > n1 && currnode->data > n2) {
            return findLCA(currnode->left, n1, n2);
        }
        if (currnode->data < n1 && currnode->data < n2) {
            return findLCA(currnode->right, n1, n2);
        }
        return currnode;
    }
};

int main() {
    Umaima_Lab11 BST;
    BST.insertrec(50);
    BST.insertrec(30);
    BST.insertrec(20);
    BST.insertrec(40);
    BST.insertrec(70);
    BST.insertrec(60);
    BST.insertrec(80);
    int n1 = 20, n2 = 40;
    node* ancestor = BST.findLCA(n1, n2);
    if (ancestor != nullptr) {
        cout << "least common ancestor of " << n1 << " and " << n2 << " is " << ancestor->data << endl;
    } else {
        cout << "least common ancestor does not exist" << endl;
    }
    n1 = 20, n2 = 80;
    ancestor = BST.findLCA(n1, n2);
    if (ancestor != nullptr) {
        cout << "least common ancestor of " << n1 << " and " << n2 << " is " <<ancestor->data << endl;
    } else {
        cout << "least common ancestor does not exist" << endl;
    }
    return 0;
}
