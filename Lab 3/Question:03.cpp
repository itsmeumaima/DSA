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
        cout << "The stack is: ";
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
    void checkPalindrome() {
        bool ans = true;
        for (int i = 0; i < top / 2 + 1; i++) {
            if (arr[i] != arr[top - i]) {
                ans = false;
                break;
            }
        }
        if (ans) {
            cout << "The given string is a palindrome." << endl;
        }
        else {
            cout << "The given string is not a palindrome." << endl;
        }
    }
};
int main() {
    Umaima_Lab03 stack(10);
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    for (char j : s) {
        stack.push(j);
    }
    stack.checkPalindrome();
    stack.display();
    return 0;
}
