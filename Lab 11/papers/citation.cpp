#include <iostream>
#include <string>

using namespace std;

class Paper {
public:
    string title;
    int citation;
    Paper(string t, int no) : title(t), citation(no) {}
};

class BSTNode {
public:
    Paper* data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Paper* p) : data(p), left(nullptr), right(nullptr) {}
};

class ListNode {
public:
    Paper* data;
    ListNode* next;
    ListNode(Paper* val) : data(val), next(nullptr) {}
};

class Papers {
private:
    BSTNode* root;

    void insert(BSTNode*& root, Paper* p) {
        if (root == nullptr) {
            root = new BSTNode(p);
        }
        else if (p->title < root->data->title) {
            insert(root->left, p);
        }
        else {
            insert(root->right, p);
        }
    }

    void inorderTraversal(BSTNode* root, ListNode*& head, ListNode*& tail) {
        if (root == nullptr) return;

        inorderTraversal(root->left, head, tail);

        if (root->data->citation > 10) {
            ListNode* newNode = new ListNode(root->data);
            if (head == nullptr) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        inorderTraversal(root->right, head, tail);
    }

public:
    Papers() : root(nullptr) {}

    void insertPaper(Paper* p) {
        insert(root, p);
    }

    ListNode* getHighlyCitedPapers() {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        inorderTraversal(root, head, tail);
        return head;
    }

    void printInorder(BSTNode* node) {
        if (node == nullptr) return;
        printInorder(node->left);
        cout << "Title: " << node->data->title << ", Citations: " << node->data->citation << endl;
        printInorder(node->right);
    }

    void display() {
        printInorder(root);
    }
};

int main() {
    Papers papers;

    papers.insertPaper(new Paper("Paper A", 15));
    papers.insertPaper(new Paper("Paper B", 8));
    papers.insertPaper(new Paper("Paper C", 20));
    papers.insertPaper(new Paper("Paper D", 5));
    papers.insertPaper(new Paper("Paper E", 12));

    cout << "Inorder traversal of BST:" << endl;
    papers.display();

    ListNode* highlyCited = papers.getHighlyCitedPapers();

    cout << "\nHighly Cited Papers:" << endl;
    while (highlyCited != nullptr) {
        cout << "Title: " << highlyCited->data->title << ", Citations: " << highlyCited->data->citation << endl;
        highlyCited = highlyCited->next;
    }

    return 0;
}
