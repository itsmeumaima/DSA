#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {};
};

class Umaima_Lab11 {
private:
    node* root;
public:
    Umaima_Lab11() : root(nullptr) {};

    void insertrec(int val) {
        root = insert(root, val);
    }

    void sum() {
        cout << "The sum is: ";
        int total = preOrderTraversal(root);
        cout << total << endl;
    }

private:
    node* insert(node* root, int value) {
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

    int preOrderTraversal(node* currnode) {
        if (currnode == nullptr) {
            return 0;
        }
        int sum = currnode->data;
        sum += preOrderTraversal(currnode->left);
        sum += preOrderTraversal(currnode->right);
        return sum;
    }
};

int main() {
    Umaima_Lab11 BST;
    BST.insertrec(10);
    BST.insertrec(1);
    BST.insertrec(2);
    BST.insertrec(4);
    BST.insertrec(11);
    BST.sum();
    return 0;
}

