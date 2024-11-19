#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 50;

void readMatrix(int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortMatrixInPlace(int matrix[][MAX_SIZE], int rows, int cols) {
    int total = rows * cols;

    for (int i = 0; i < total - 1; ++i) {
        for (int j = 0; j < total - i - 1; ++j) {
            int row1 = j / cols, col1 = j % cols;
            int row2 = (j + 1) / cols, col2 = (j + 1) % cols;

            if (matrix[row1][col1] > matrix[row2][col2]) {
                mySwap(matrix[row1][col1], matrix[row2][col2]);
            }
        }
    }
}

int main() {
    unsigned rows, cols;
    cin >> rows >> cols;

    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, rows, cols);

    sortMatrixInPlace(matrix, rows, cols);

    cout << endl << "Sorted: " << endl;
    printMatrix(matrix, rows, cols);
}
