#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 10;

void readMatrix(int matrix[][MAX_SIZE], unsigned n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

int getRowSum(const int matrix[][MAX_SIZE], unsigned n, unsigned rowIndex) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[rowIndex][i];
    }
    return sum;
}

int getColSum(const int matrix[][MAX_SIZE], unsigned n, unsigned colIndex) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][colIndex];
    }
    return sum;
}

int getMainDiagonalSum(const int matrix[][MAX_SIZE], unsigned n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int getSecondaryDiagonalSum(const int matrix[][MAX_SIZE], unsigned n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][n - i - 1];
    }
    return sum;
}

bool isMagicSquare(const int matrix[][MAX_SIZE], unsigned n) {
    int rowSum = getRowSum(matrix, n, 0);
    int colSum = getColSum(matrix, n, 0);
    
    if (getMainDiagonalSum(matrix, n) != getSecondaryDiagonalSum(matrix, n)) {
        return false;
    }

    for (int i = 1; i < n; i++) {
        if (getRowSum(matrix, n, i) != rowSum || getColSum(matrix, n, i) != colSum) {
            return false;
        }
    }

    return true;
}

int main() {
    unsigned n;
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n);

    cout << (isMagicSquare(matrix, n) ? "magic" : "not magic");
}
