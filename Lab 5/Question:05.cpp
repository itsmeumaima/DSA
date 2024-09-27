#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Umaima_Lab05 {
    vector<vector<int>> trips;
public:
    void input() {
        int n;
        cout << "Enter the number of intervals: ";
        cin >> n;
        trips.resize(n);
        for (int i = 0; i < n; ++i) {
            int numPassengers, start, end;
            cout << "Enter interval " << i + 1 << " (number of passengers, start, end): ";
            cin >> numPassengers >> start >> end;
            trips[i] = { numPassengers, start, end };
        }
    }
    bool canAccommodate(int capacity) {
        vector<pair<int, int>> events;
        for (const auto& trip : trips) {
            events.emplace_back(trip[1], trip[0]);  
            events.emplace_back(trip[2], -trip[0]); 
        }
        sort(events.begin(), events.end());
        int currentPassengers = 0;
        for (const auto& event : events) {
            currentPassengers += event.second; 
            if (currentPassengers > capacity) { 
                return false;
            }
        }
        return true;
    }
};
int main() {
    Umaima_Lab05 lab;
    lab.input();

    int capacity;
    cout << "Enter the capacity of the car: ";
    cin >> capacity;
    if (lab.canAccommodate(capacity)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}
