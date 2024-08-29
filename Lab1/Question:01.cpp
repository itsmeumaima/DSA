#include <iostream>
using namespace std;

int main() {
    int row, col;

    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;

    int arr[row][col]; 
    cout << "Enter array data:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter data for position (" << i << "," << j << "): ";
            cin >> arr[i][j];
        }
    }
    int ans[row * col];  
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
    return 0;
}
