#include <iostream>
using namespace std;
class Umaima_Lab01 {
    int row;
    int col;
    int** arr;
public:
    Umaima_Lab01(int r, int c) : row(r), col(c) {
        arr = new int* [row];
        for (int i = 0; i < row; ++i) {
            arr[i] = new int[col];
        }
    }
    void inputArrayData() {
        cout << "Enter data for array:" << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << "Enter data :";
                cin >> arr[i][j];
            }
        }
    }
    void ColumnMajorOrder() const {
        int* ans = new int[row * col];
        int k = 0;
        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                ans[k] = arr[i][j];
                k++;
            }
        }
        cout << "Column major order of the matrix is: " << endl;
        for (int i = 0; i < k; i++) {
            cout << ans[i] << "  ";
        }
        cout << endl;
        delete[] ans;
    }
    ~Umaima_Lab01() {
        for (int i = 0; i < row; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
int main() {
    int row, col;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    Umaima_Lab01 matrix(row, col);
    matrix.inputArrayData();
    matrix.ColumnMajorOrder();
    return 0;
}
