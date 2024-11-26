#include <iostream>
using namespace std;

const unsigned MAX_SIZE = 50;

void printCol(const int matrix[][MAX_SIZE], unsigned size, int colIndex) {
    for (int i = 0; i < size; i++) {
        cout << matrix[i][colIndex] << " ";
    }
}

void printColReversed(const int matrix[][MAX_SIZE], unsigned size, int colIndex) {
    for (int i = size - 1; i >= 0; i--) {
        cout << matrix[i][colIndex] << " ";
    }
}

void readMatrix(int matrix[][MAX_SIZE], unsigned size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

int main() {
    unsigned size;

    cin >> size;
    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, size);

    printCol(matrix, size, 0);

    // print rightmost and leftmost possible upwards / downwards
    unsigned left = 1, right = size - 1;
    int counter = 0;
    while (left < right) {
        if (counter % 2 == 0) {
            printColReversed(matrix, size, right);
            printColReversed(matrix, size, left);
        }
        else {
            printCol(matrix, size, right);
            printCol(matrix, size, left);
        }

        left++;
        right--;
        counter++;
    }

    // if the size is even, there will be one remaining column in the center
    if (size % 2 == 0) {
        if (counter % 2 == 0) {
            printColReversed(matrix, size, left);
        }
        else {
            printCol(matrix, size, left);
        }
    }
}
