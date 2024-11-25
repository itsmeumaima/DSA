#include <iostream>
#include <string>

using namespace std;

// Delivery class representing a delivery with an ID and a status
class Delivery {
public:
    int id;
    string status;

    Delivery(int id, string status) : id(id), status(status) {}
};

// Node for the Circular Linked List
class CircularListNode {
public:
    Delivery* data;
    CircularListNode* next;

    CircularListNode(Delivery* delivery) : data(delivery), next(nullptr) {}
};

// Node for the Doubly Linked List
class DoublyListNode {
public:
    Delivery* data;
    DoublyListNode* prev;
    DoublyListNode* next;

    DoublyListNode(Delivery* delivery) : data(delivery), prev(nullptr), next(nullptr) {}
};

// Circular Linked List class for managing delivery stops
class CircularLinkedList {
private:
    CircularListNode* head;
    CircularListNode* tail;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    void addDelivery(Delivery* delivery) {
        CircularListNode* newNode = new CircularListNode(delivery);
        if (!head) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Making it circular
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Maintaining circularity
        }
    }

    void printDeliveries() {
        if (!head) return;
        CircularListNode* temp = head;
        do {
            cout << "Delivery ID: " << temp->data->id << ", Status: " << temp->data->status << endl;
            temp = temp->next;
        } while (temp != head);
    }

    CircularListNode* getHead() {
        return head;
    }
};

// Doubly Linked List class for managing pending deliveries
class DoublyLinkedList {
private:
    DoublyListNode* head;
    DoublyListNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addPendingDelivery(Delivery* delivery) {
        DoublyListNode* newNode = new DoublyListNode(delivery);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printPendingDeliveries() {
        DoublyListNode* temp = head;
        while (temp) {
            cout << "Pending Delivery ID: " << temp->data->id << ", Status: " << temp->data->status << endl;
            temp = temp->next;
        }
    }
};

// Function to transfer pending deliveries from CircularLinkedList to DoublyLinkedList
void transferPendingDeliveries(CircularLinkedList& circularList, DoublyLinkedList& doublyList) {
    CircularListNode* current = circularList.getHead();
    if (!current) return;

    do {
        if (current->data->status == "pending") {
            doublyList.addPendingDelivery(current->data);
        }
        current = current->next;
    } while (current != circularList.getHead());
}

// Main function to demonstrate the functionality
int main() {
    CircularLinkedList deliveryStops;
    DoublyLinkedList pendingDeliveries;

    // Adding some deliveries
    deliveryStops.addDelivery(new Delivery(1, "completed"));
    deliveryStops.addDelivery(new Delivery(2, "pending"));
    deliveryStops.addDelivery(new Delivery(3, "completed"));
    deliveryStops.addDelivery(new Delivery(4, "pending"));

    cout << "All Deliveries:" << endl;
    deliveryStops.printDeliveries();

    transferPendingDeliveries(deliveryStops, pendingDeliveries);

    cout << "\nPending Deliveries:" << endl;
    pendingDeliveries.printPendingDeliveries();

    return 0;
}
