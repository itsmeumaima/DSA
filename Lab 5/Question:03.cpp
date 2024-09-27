#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Umaima_Lab05 {
    vector<vector<int>> arr;
public:
    void input() {
        int n;
        cout << "Enter the number of intervals: ";
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; ++i) {
            int start, end;
            cout << "Enter interval " << i + 1 << " (start and end): ";
            cin >> start >> end;
            arr[i] = { start, end };
        }
    }
    vector<vector<int>> merge() {
        if (arr.empty()) return {};

        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        result.push_back(arr[0]);

        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], arr[i][1]);
            }
            else {
                result.push_back(arr[i]);
            }
        }
        return result;
    }
    void display(const vector<vector<int>>& answer) {
        cout << "Merged intervals: ";
        for (const auto& interval : answer) {
            cout << "[" << interval[0] << "," << interval[1] << "] ";
        }
        cout << endl;
    }
};
int main() {
    Umaima_Lab05 lab;
    lab.input();
    vector<vector<int>> Intervals = lab.merge();
    lab.display(Intervals);
    return 0;
}
