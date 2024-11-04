#include <iostream>

using namespace std;

const unsigned int ROWS = 4;
const unsigned int COLS = 4;

void squareEvenElements(int matrix[ROWS][COLS]);
void printMatrix(const int matrix[ROWS][COLS]);

int main() {
    int matrix[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cin >> matrix[i][j];
        }
    }

    squareEvenElements(matrix);
    printMatrix(matrix);

    return 0;
}

void squareEvenElements(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] % 2 == 0) {
                matrix[i][j] *= matrix[i][j];
            }
        }
    }
}

void printMatrix(const int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrix[i][j] << (j == COLS - 1 ? "\n" : " ");
        }
    }
}