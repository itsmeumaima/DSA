#include <iostream>
#include <string>
using namespace std;

const int CREDIT_HOUR = 3;
class Umaima_Lab01 {
    int numStudents;
    int numCourses;
    string* names;
    float** arr;

public:
    Umaima_Lab01(int students, int courses) : numStudents(students), numCourses(courses) {
        names = new string[numStudents];
        arr = new float* [numStudents];
        for (int i = 0; i < numStudents; ++i) {
            arr[i] = new float[numCourses];
        }
    }
    void inputStudentData() {
        for (int i = 0; i < numStudents; i++) {
            cout << "Enter the name of student " << i + 1 << ": ";
            cin >> names[i];
            for (int j = 0; j < numCourses; j++) {
                cout << "Enter GPA for course " << j + 1 << " : ";
                cin >> arr[i][j];
            }
            cout << endl;
        }
    }
    void calculateGPA() const {
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
            cout << "GPA of " << names[k] << " is: " << ans[k] << endl;
        }
        delete[] ans;
    }
    ~Umaima_Lab01() {
        for (int i = 0; i < numStudents; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
        delete[] names;
    }
};
int main() {
    int numStudents, numCourses;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    Umaima_Lab01 lab(numStudents, numCourses);
    lab.inputStudentData();
    lab.calculateGPA();
    return 0;
}
