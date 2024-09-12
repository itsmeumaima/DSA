#include <iostream>
#include <string>
using namespace std;
class Umaima_Lab03 {
    int capacity;
    int top;
    char* arr;
public:
    Umaima_Lab03(int s) {
        capacity = s;
        top = -1;
        arr = new char[capacity];
    }
    ~Umaima_Lab03() {
        delete[] arr;
    }
    void push(char element) {
        if (top == capacity - 1) {
            cout << "Stack overflow. Resizing..." << endl;
            resize();
        }
        top += 1;
        arr[top] = element;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack underflow." << endl;
        }
        else {
            top -= 1;
        }
    }
    int size() const {
        return top + 1;
    }
    void display() const {
        for (int i = 0; i <= top; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
    void resize() {
        char* temp = new char[capacity * 2];
        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = capacity * 2;
    }
    void processString(const string& str) {
        for (char ch : str) {
            if (ch == '#') {
                pop();
            }
            else {
                push(ch);
            }
        }
    }
    bool isEqual(const Umaima_Lab03& obj) const {
        if (top != obj.top) return false;
        for (int i = 0; i <= top; i++) {
            if (arr[i] != obj.arr[i]) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Umaima_Lab03 stack1(10);
    Umaima_Lab03 stack2(10);
    string s, t;
    cout << "Enter first string: ";
    getline(cin, s);
    cout << "Enter second string: ";
    getline(cin, t);
    stack1.processString(s);
    stack2.processString(t);
    if (stack1.isEqual(stack2)) {
        cout << "Both strings are equal." << endl;
    }
    else {
        cout << "Strings are not equal." << endl;
    }
    return 0;
}
