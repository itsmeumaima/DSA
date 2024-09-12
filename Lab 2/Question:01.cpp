#include <iostream>
using namespace std;
class Umaima_Lab02 {
private:
    int row;
    int col;
    int** array;
public:
    Umaima_Lab02() {
        cout << "Enter number of rows: ";
        cin >> row;
        cout << "Enter number of columns: ";
        cin >> col;
        array = new int* [row];
        for (int i = 0; i < row; i++) {
            array[i] = new int[col];
        }
    }
    void inputdata() {
        cout << "Enter data for 2D array :" << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << "Enter data for (" << i << "," << j << "): ";
                cin >> array[i][j];
            }
        }
    }
    void sortArray() {
        int size = row * col;
        int* tempArray = new int[size];
        int index = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                tempArray[index++] = array[i][j];
            }
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (tempArray[j] > tempArray[j + 1]) {
                    int temp = tempArray[j];
                    tempArray[j] = tempArray[j + 1];
                    tempArray[j + 1] = temp;
                }
            }
        }
        index = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                array[i][j] = tempArray[index++];
            }
        }
        delete[] tempArray;
    }
    void search(int target) {
        if (row == 0 || col == 0) {
            cout << "Enter the values!";
            return;
        }
        int left = 0;
        int right = row * col - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_value = array[mid / col][mid % col];

            if (target == mid_value) {
                cout << "The target value: " << target << " is found at (" << mid / col << "," << mid % col << ") position" << endl;
                return;
            }
            else if (target > mid_value) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        cout << "The target value: " << target << " is not found in the array." << endl;
    }
    ~Umaima_Lab02() {
        for (int i = 0; i < row; i++) {
            delete[] array[i];
        }
        delete[] array;
    }
};
int main() {
    Umaima_Lab02 b1;
    b1.inputdata();
    b1.sortArray();
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    b1.search(target);

    return 0;
}
