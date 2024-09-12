#include <iostream>
using namespace std;
class Umaima_Lab02 {
    int row;
    int col;
    int** mat;

public:
    Umaima_Lab02(int r, int c) : row(r), col(c) {
        mat = new int* [row];
        for (int i = 0; i < row; i++) {
            mat[i] = new int[col];
        }
    }
    Umaima_Lab02() {
        cout << "Enter number of rows: ";
        cin >> row;
        cout << "Enter number of columns: ";
        cin >> col;
        mat = new int* [row];
        for (int i = 0; i < row; i++) {
            mat[i] = new int[col];
        }
    }
    ~Umaima_Lab02() {
        for (int i = 0; i < row; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
    void inputData() {
        cout << "Enter data for matrix:" << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << "Enter data for element [" << i << "][" << j << "]: ";
                cin >> mat[i][j];
            }
        }
    }
    void displayMatrix() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    Umaima_Lab02 addition(const Umaima_Lab02& m) const {
        Umaima_Lab02 result(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }
    Umaima_Lab02 subtraction(const Umaima_Lab02& m) const {
        Umaima_Lab02 result(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }
        return result;
    }
    Umaima_Lab02 multiplication(const Umaima_Lab02& m) const {
        if (col != m.row) {
            cout << "Matrix multiplication is not possible with given dimensions." << endl;
            return Umaima_Lab02();
        }
        Umaima_Lab02 result(row, m.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < m.col; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < col; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }
    Umaima_Lab02 transpose() const {
        Umaima_Lab02 result(col, row);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result;
    }
    void scalarMultiplication(int no) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mat[i][j] *= no;
            }
        }
    }
};
int main() {
    Umaima_Lab02 m1(2, 2);
    Umaima_Lab02 m2(2, 2);
    m1.inputData();
    m2.inputData();
    cout << "Addition:" << endl;
    Umaima_Lab02 result = m1.addition(m2);
    result.displayMatrix();
    cout << "Subtraction:" << endl;
    Umaima_Lab02 result1 = m1.subtraction(m2);
    result1.displayMatrix();
    cout << "Multiplication:" << endl;
    Umaima_Lab02 result2 = m1.multiplication(m2);
    result2.displayMatrix();
    cout << "Transpose of first matrix:" << endl;
    Umaima_Lab02 transposedMatrix = m1.transpose();
    transposedMatrix.displayMatrix();
    cout << "Scalar Multiplication:" << endl;
    m1.scalarMultiplication(2);
    m1.displayMatrix();
    return 0;
}
