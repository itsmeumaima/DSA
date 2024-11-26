#include <iostream>
using namespace std;

class score {
public:
    int id;
    int scores;
    score(int i, int s) : id(i), scores(s) {};
};

class snode {
public:
    score* data;
    snode* next;
    snode(score* d) : data(d), next(nullptr) {};
};

class cnode {
public:
    score* data;
    cnode* next;
    cnode(score* d) : data(d), next(nullptr) {};
};

class single {
    snode* head;
public:
    single() : head(nullptr) {};

    void insert(score* sc) {
        snode* newnode = new snode(sc);
        if (head == nullptr) {
            head = newnode;
        }
        else {
            snode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty\n";
            return;
        }
        snode* temp = head;
        while (temp != nullptr) {
            cout << "ID = " << temp->data->id;
            cout << "\tMarks = " << temp->data->scores << endl;
            temp = temp->next;
        }
    }

    snode* gethead() {
        return head;
    }

    void deletenode(score* s) {
        snode* prev = nullptr;
        snode* curr = head;

        // Search for the node with the given score
        while (curr != nullptr && curr->data->id != s->id) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            // Node not found
            cout << "Node with ID " << s->id << " not found.\n";
            return;
        }

        // If the node to delete is the head
        if (prev == nullptr) {
            head = curr->next;  // Move head to next node
        }
        else {
            prev->next = curr->next;  // Bypass the current node
        }

        delete curr;  // Delete the node itself, but not the score object
    }
};

class circular {
    cnode* head;
    cnode* tail;
public:
    circular() : head(nullptr), tail(nullptr) {};

    void insert(score* sc) {
        cnode* newnode = new cnode(sc);
        if (head == nullptr && tail == nullptr) {
            head = tail = newnode;
            tail->next = tail;
        }
        else {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty\n";
            return;
        }
        cnode* temp = head;
        do {
            cout << "ID = " << temp->data->id;
            cout << "\tMarks = " << temp->data->scores << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

void highscore(single& s, circular& c) {
    snode* temp = s.gethead();

    while (temp != nullptr) {
        snode* nextNode = temp->next; // Save the next node before deletion

        if (temp->data->scores > 90) {
            c.insert(temp->data);  // Move to circular list
            s.deletenode(temp->data);  // Delete the node from singly linked list
        }

        temp = nextNode;  // Move to the next node safely
    }
}

int main() {
    single s1;
    circular c1;
    s1.insert(new score(1, 100));
    s1.insert(new score(2, 50));
    s1.insert(new score(3, 300));
    s1.insert(new score(4, 70));
    s1.insert(new score(5, 90));

    cout << "Lower scores before transfer:\n";
    s1.display();

    cout << "Higher scores before transfer:\n";
    //c1.insert(new score(6, 900)); // Pre-inserted score for display
    c1.display();

    highscore(s1, c1);

    cout << "Higher scores after transfer:\n";
    c1.display();

    cout << "Lower scores after transfer:\n";
    s1.display();

    return 0;
}
