#include <iostream>
#include <vector>
using namespace std;

void inputdata(vector<int>& A, vector<int>& B) {
    cout << "Enter elements for array1:" << endl;
    for (int i = 0; i < A.size(); ++i) {
        cin >> A[i];
    }
    cout << "Enter elements for array2:" << endl;
    for (int i = 0; i < B.size(); ++i) {
        cin >> B[i];
    }
}
int main() {
    int no1, no2;
    cout << "Enter the number of elements for array1: ";
    cin >> no1;
    cout << "Enter the number of elements for array2: ";
    cin >> no2;

    vector<int> A(no1);
    vector<int> B(no2);

    inputdata(A, B);

    int X, Y;
    cout << "Enter the scalar value X: ";
    cin >> X;
    cout << "Enter the scalar value Y: ";
    cin >> Y;

    if (A.size() != B.size()) {
        cout << "Arrays must have the same number of elements for operations." << endl;
        return 1;
    }
    int size = A.size();
    vector<int> result(size);

    for (int i = 0; i < size; ++i) {
        result[i] = X * A[i] + Y * B[i];
    }

    cout << "Result of XA + YB: (";
    for (int i = 0; i < size; ++i) {
        cout << result[i] << ",";
    }
    cout << ")"<<endl;

    int dotProduct = 0;
    for (int i = 0; i < size; ++i) {
        dotProduct += A[i] * B[i];
    }

    cout << "Result of A . B: " << dotProduct << endl;
    return 0;
}
