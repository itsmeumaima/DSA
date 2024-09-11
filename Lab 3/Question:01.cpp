#include <iostream>
using namespace std;
const int max_size = 20;
class Umaima_Lab03 {
    int capacity;
    int top;
    int* arr;
public:
    Umaima_Lab03(int s) {
        capacity = s;
        top = -1;
        arr = new int[capacity];
    }
    ~Umaima_Lab03() {
        delete[] arr;
    }
    void push(int element) {
        if (top == capacity - 1) {
            cout << "Stack overflow." << endl;
            resize();
        }
        top += 1;
        arr[top] = element;
        cout << "Successfully push the element." << endl;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack underflow." << endl;
        }
        else {
            top -= 1;
            cout << "Successfully pop the element." << endl;
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
    void size() {
        cout << "The size of stack is : " << top + 1 << endl;
    }
    void display() {
        cout << "The stack is :" << endl;
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;}
    void resize() {
        int* temp = new int[capacity * 2];
        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = capacity * 2;}
};
int main() {
    Umaima_Lab03 stack(3);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.display();
    stack.pop();
    stack.size();cout << endl;
    stack.peek();
    stack.push(5);
    stack.push(1);  
    stack.display();
    return 0;
}
