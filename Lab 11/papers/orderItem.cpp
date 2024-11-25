#include <iostream>
using namespace std;

class order {
public:
    string name;
    int quantity;
    order(string t, int c) : name(t), quantity(c) {}
};

class tnode {
public:
    order* data;
    tnode* left;
    tnode* right;
    tnode(order* p) : data(p), left(nullptr), right(nullptr) {}
};

class lnode {
public:
    order* data;
    lnode* next;
    lnode(order* p) : data(p), next(nullptr) {}
};

class linkedlist {
    lnode* head;
    lnode* tail;
public:
    linkedlist() : head(nullptr), tail(nullptr) {}
    void insert(order* ord) {
        lnode* neworder = new lnode(ord);
        if (head == nullptr) {
            head = neworder;
            tail = neworder;
        }
        else {
            tail->next = neworder;
            tail = neworder;
        }
    }
    void display() {
        lnode* temp = head;
        while (temp != nullptr) {
            cout << "Item name = " << temp->data->name;
            cout << "\tQuantity = " << temp->data->quantity << endl;
            temp = temp->next;
        }
    }
    lnode* gethead() {
        return head;
    }
    lnode* gettail() {
        return tail;
    }
};

class tree {
    tnode* root;
    tnode* insertquan(tnode* node, order* ord) {
        if (node == nullptr) {
            return new tnode(ord);
        }
        if (ord->name < node->data->name) {
            node->left = insertquan(node->left, ord);
        }
        else {
            node->right = insertquan(node->right, ord);
        }
        return node;
    }
public:
    tree() : root(nullptr) {}
    void insert(order* ord) {
        root = insertquan(root, ord);
    }
    void inordertrav(tnode* node) {
        if (node == nullptr) return;
        inordertrav(node->left);
        cout << "Item name = " << node->data->name;
        cout << "\tQuantity = " << node->data->quantity << endl;
        inordertrav(node->right);
    }
    void inorder() {
        inordertrav(root);
    }
};

void increseitem(tree& t, linkedlist& l) {
    lnode* curr = l.gethead();
    if (curr == nullptr) {
        return;
    }
    while (curr != nullptr) {
        if (curr->data->quantity > 1) {
            t.insert(curr->data);
        }
        curr = curr->next;
    }
}

int main() {
    linkedlist l1;
    tree t1;
    l1.insert(new order("Shoes", 1));
    l1.insert(new order("Earrings", 2));
    l1.insert(new order("Hairband", 1));
    l1.insert(new order("Watch", 3));
    l1.insert(new order("dress", 2));
    cout << "Linked List:" << endl;
    l1.display();
    increseitem(t1, l1);
    cout << "\nBinary Search Tree (Inorder Traversal):" << endl;
    t1.inorder();
}
