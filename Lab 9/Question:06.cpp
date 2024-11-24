#include <iostream>
using namespace std;

class node {
public:
    string data;
    node* prev;
    node* next;
    node(string val) : data(val), prev(nullptr), next(nullptr) {};
};

class Linkedlist {
    node* head;
    node* current;
    node* tail;
public:
    Linkedlist(string st) {
        head = new node(st);
        current = head;
        tail = head;
    }
    void visit(string url) {
        node* newnode = new node(url);
        current->next = newnode;
        newnode->next = nullptr;
        newnode->prev = current;
        current = newnode;
        tail = newnode;
    }
    void back(int count) {
        while (count-- > 0 && current->prev != nullptr) {
            current = current->prev;
        }
        cout << current->data << "\n";
    }
    void forward(int count) {
        while (count-- > 0 && current->next != nullptr) {
            current = current->next;
        }
        cout << current->data << "\n";
    }
};

int main() {
    Linkedlist l("Google.com");
    l.visit("leetcode.com");
    l.visit("Youtube.com");
    l.back(1);
    l.forward(1);
    l.visit("Instagram.com");
    l.forward(2); // This should only move forward until it reaches the last node.
    l.back(1);
    l.back(1);

    return 0;
}
