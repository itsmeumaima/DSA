#include <iostream>
using namespace std;
class fitness {
public:
	string name;
	float timming;
	fitness(string n, float t) :name(n), timming(t) {};
};
class Cnode {
public:
	fitness* data;
	Cnode* next;
	Cnode(fitness* d) :data(d), next(nullptr) {};
};
class Dnode {
public:
	fitness* data;
	Dnode* next;
	Dnode* prev;
	Dnode(fitness* d) :data(d), next(nullptr), prev(nullptr) {};
};
class circular {
	Cnode* head;
	Cnode* tail;
public:
	circular() :head(nullptr), tail(nullptr) {};
	void insert(fitness* fit) {
		Cnode* val = new Cnode(fit);
		if (head == nullptr) {
			head = val;
			tail = val;
			val->next = head;
		}
		else {
			tail->next = val;
			tail = val;
			tail->next = head;
		}
	}
	void display() {
		if (head == nullptr) {
			cout << "Empty\n";
			return;
		}
		Cnode* temp = head;
		cout << "THe fitness data\n";
		do {
			cout << "Name = " << temp->data->name;
			cout << "Timming = " << temp->data->timming;
			cout << endl;
			temp = temp->next;
		} while (temp != head);
	}
	Cnode* gethead() {
		return head;
	}
};
class doubly {
	Dnode* head;
	Dnode* tail;
	public:
		doubly() :head(nullptr), tail(nullptr) {};
		void insertdouble(fitness* fit) {
			Dnode* val = new Dnode(fit);
			if (head == nullptr) {
				head = val;
				tail = val;
			}
			else {
				tail->next = val;
				val->prev = tail;
				tail = val;
			}
		}
		void displaydouble() {
			if (head == nullptr) {
				cout << "Empty\n";
				return;
			}
			Dnode* temp = head;
			cout << "THe fitness data\n";
			do {
				cout << "Name = " << temp->data->name;
				cout << "Timming = " << temp->data->timming;
				cout << endl;
			} while (temp != head);
		}
		
};
void extendtimming(circular& c, doubly& d) {
	Cnode* temp = c.gethead();
	if (!temp) return;
	do {
		if (temp->data->timming > 1) {
			d.insertdouble(temp->data);
		}
		temp = temp->next;
	} while (temp != c.gethead());
}
int main() {
	circular c1;
	doubly d1;
	c1.insert(new fitness("Umaima", 0.5));
	c1.insert(new fitness("Umaima", 0.4));
	c1.insert(new fitness("Umaima", 0.7));
	c1.insert(new fitness("Umaima", 2));
	c1.display();
	extendtimming(c1, d1);
	d1.displaydouble();
}
