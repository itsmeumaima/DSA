#include <iostream>
using namespace std;

class matrix {
    int row;
    int col;
    int** mat;

public:
    matrix(int r, int c) : row(r), col(c) {
        mat = new int* [row];
        for (int i = 0; i < row; i++) {
            mat[i] = new int[col];
        }
    }
    matrix() {
        cout << "Enter number of rows:";
        cin >> row;
        cout << "Enter number of columns:";
        cin >> col;
        mat = new int* [row];
        for (int i = 0; i < row; i++) {
            mat[i] = new int[col];
        }
    }
    ~matrix() {
        for (int i = 0; i < row; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void inputData() {
        cout << "Enter data for matrix:" << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << "Enter data:";
                cin >> mat[i][j];
            }
        }
    }

    void displayMatrix() const {
        cout << "Matrix" << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    matrix addition(const matrix& m) const {
        matrix result(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    matrix subtraction(const matrix& m) const {
        matrix result(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }
        return result;
    }

    matrix multiplication(const matrix& m) const {
        if (col != m.row) {
            cout << "Matrix multiplication is not possible with given dimensions." << endl;
            return matrix(); 
        }
        matrix result(row, m.col);
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

    void transpose() {
        matrix result(col, row);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.mat[j][i] = mat[i][j];
            }
        }
        result.displayMatrix(); 
    }

    void scalarMultiplication() {
        int no;
        cout << "Enter the number you want to multiply:";
        cin >> no;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mat[i][j] *= no;
            }
        }
    }
};

int main() {
    matrix m1(2, 2);
    matrix m2(2, 2);
    m1.inputData();
    m2.inputData();

    cout << "Addition :" << endl;
    matrix result = m1.addition(m2);
    result.displayMatrix();

    cout << "Subtraction :" << endl;
    matrix result1 = m1.subtraction(m2);
    result1.displayMatrix();

    cout << "Multiplication :" << endl;
    matrix result2 = m1.multiplication(m2);
    result2.displayMatrix();

    cout << "Transpose :" << endl;
    m1.transpose();

    cout << "Scalar Multiplication :" << endl;
    m1.scalarMultiplication();
    m1.displayMatrix();
    return 0;
}
