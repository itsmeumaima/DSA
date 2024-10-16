#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Umaima_Lab07 {
public:
    priority_queue<int> max_queue;
    priority_queue<int, vector<int>, greater<int>> min_queue;

    void push_max(int element) {
        max_queue.push(element);
    }
    void push_min(int element) {
        min_queue.push(element);
    }
    void display_max() {
        cout << "Max Queue: ";
        while (!max_queue.empty()) {
            cout << max_queue.top() << " ";
            max_queue.pop();
        }
        cout << endl;
    }
    void display_min() {
        cout << "Min Queue: ";
        while (!min_queue.empty()) {
            cout << min_queue.top() << " ";
            min_queue.pop();
        }
        cout << endl;
    }
};
int main() {
    Umaima_Lab07 queue;
    queue.push_max(1);
    queue.push_max(12);
    queue.push_max(4);
    queue.push_max(2);
    queue.display_max();
    queue.push_min(1);
    queue.push_min(12);
    queue.push_min(4);
    queue.push_min(2);
    queue.display_min();

    return 0;
}
