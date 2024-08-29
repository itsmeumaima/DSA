#include <iostream>
using namespace std;
bool searchMatrix(int** matrix, int m, int n, int target) {
    if (m == 0 || n == 0) return false;

    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_value = matrix[mid / n][mid % n];

        if (mid_value == target) {
            return true;
        } else if (mid_value < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int m, n;

    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    int** matrix = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    bool result = searchMatrix(matrix, m, n, target);
    cout << (result ? "true" : "false") << endl;

    // Free the dynamically allocated matrix
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
