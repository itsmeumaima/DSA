#include <iostream>
#include <string>
using namespace std;

class stack {
    char arr[20];
    int top;
public:
    stack() {
        top = -1;
    }
    void push(char num) {
        if (top == 19) { // Corrected the condition to check if stack is full
            cout << "Stack is full.";
            return;
        } else {
            top++;
            arr[top] = num;
        }
    }
    char pop() {
        if (top == -1) {
            return '\0'; // Returning null character if stack is empty
        } else {
            char val = arr[top];
            top--;
            return val; // Added missing semicolon
        }
    }
};

bool isBalanced(string word) {
    stack s;
    bool result = true;

    for (char i : word) {
        if (i == '{' || i == '[' || i == '(') { // Corrected logical operator
            s.push(i);
        } else {
            char ans = s.pop();
            if ((i == '}' && ans == '{') || (i == ']' && ans == '[') || (i == ')' && ans == '(')) { // Corrected logical operator
                result = true;
            } else {
                return false;
            }
        }
    }
    if (s.pop() != '\0') { // Check if stack is empty at the end
        return false;
    }
    return result;
}

int main() {
    string word;
    cout << "Enter the parenthesis string: ";
    cin >> word;
    
    bool result = isBalanced(word);
    if (result) {
        cout << "The parenthesis string is balanced." << endl;
    } else {
        cout << "The parenthesis string is not balanced." << endl;
    }
    
    return 0;
}
