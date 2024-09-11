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
            cout << arr[top];
            top -= 1;
        }
    }
    void peek() {
        if (top == -1) {
            cout << "The stack is empty." << endl;
        }
        else {
            cout << "The top element in the stack is: " << arr[top] << endl;
        }
    }
    void isempty() {
        if (top == -1) {
            cout << "The stack is empty." << endl;
        }
        else {
            cout << "The stack is not empty." << endl;
        }
    }
    int size() {
        return top + 1;
    }
    void display() {
        cout << "The stack is :" << endl;
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
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
};

int main() {
    Umaima_Lab03 stack(6);
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    for (char j : s) {
        stack.push(j);
    }
    int size = stack.size();
    cout << "The reversed string is: " << endl;
    for (int i = 0; i < size; i++) {
        stack.pop();
    }
    return 0;
}
