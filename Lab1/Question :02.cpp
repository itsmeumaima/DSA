#include <iostream>
#include <string>
using namespace std;

const int CREDIT_HOUR = 3;

void gpa(float arr[5][5], string name[]) {
    float ans[5];
    for (int k = 0; k < 5; k++) {
        float total = 0;
        int gradeCount = 0;
        for (int a = 0; a < 5; a++) {
            if (arr[k][a] == -1) {
                continue;
            }
            total += arr[k][a] * CREDIT_HOUR;
            gradeCount++;
        }
        if (gradeCount > 0) {
            ans[k] = total / (gradeCount * CREDIT_HOUR);
        } else {
            ans[k] = 0.0; 
        }
    }
    for (int k = 0; k < 5; k++) {
        cout << "GPA of " << name[k] << " is: " << ans[k] << endl;
    }
}
int main() {
    string name[] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};
    float arr[5][5] = {
        {3.66, 3.33, 4.0, 3.0, 2.66},
        {3.33, 3.0, 3.66, 3.0, -1},
        {4.0, 3.66, 2.66, -1, -1},
        {2.66, 2.33, 4.0, -1, -1}, 
        {3.33, 3.66, 4.0, 3.0, 3.33} 
    };
    gpa(arr, name);

    return 0;
}
