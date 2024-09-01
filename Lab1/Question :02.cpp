#include <iostream>
#include <string>
using namespace std;
const int CREDIT_HOUR = 3;
void gpa(float** arr, string* name, int numStudents, int numCourses) {
    float* ans = new float[numStudents];
    for (int k = 0; k < numStudents; k++) {
        float total = 0;
        int gradeCount = 0;
        for (int a = 0; a < numCourses; a++) {
            if (arr[k][a] == -1) {
                continue;
            }
            total += arr[k][a] * CREDIT_HOUR;
            gradeCount++;
        }
        if (gradeCount > 0) {
            ans[k] = total / (gradeCount * CREDIT_HOUR);
        }
        else {
            ans[k] = 0.0;
        }
    }
    for (int k = 0; k < numStudents; k++) {
        cout << "GPA of " << name[k] << " is: " << ans[k] << endl;
    }
    delete[] ans;
}
int main() {
    int numStudents, numCourses;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    string* name = new string[numStudents];
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    float** arr = new float* [numStudents];
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> name[i];
        arr[i] = new float[numCourses];
        for (int j = 0; j < numCourses; j++) {
            cout << "Enter GPA for course " << j + 1 << " :";
            cin >> arr[i][j];
        }
        cout << endl;
    }
    gpa(arr, name, numStudents, numCourses);
    for (int i = 0; i < numStudents; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] name;
    return 0;
}
