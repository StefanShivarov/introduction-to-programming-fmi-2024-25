#include <iostream>

using namespace std;

const unsigned int MAX_N = 10;

void readMatrix(int matrix[MAX_N][MAX_N], const unsigned int n);
int calcRowSum(const int matrix[MAX_N][MAX_N], const unsigned int n, const unsigned int row);
int calcColSum(const int matrix[MAX_N][MAX_N], const unsigned int n, const unsigned int col);
int calcFirstDiagonalSum(const int matrix[MAX_N][MAX_N], const unsigned int n);
int calcSecondDiagonalSum(const int matrix[MAX_N][MAX_N], const unsigned int n);
bool isMagicSquare(const int matrix[MAX_N][MAX_N], const unsigned int n);

int main() {
    int matrix[MAX_N][MAX_N];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    readMatrix(matrix, n);

    cout << (isMagicSquare(matrix, n) ? "magic" : "not magic") << endl;

    return 0;
}

void readMatrix(int matrix[MAX_N][MAX_N], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
}

int calcRowSum(const int matrix[MAX_N][MAX_N], const unsigned int n, const unsigned int row) {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += matrix[row][i];
    }

    return sum;
}

int calcColSum(const int matrix[MAX_N][MAX_N], const unsigned int n, const unsigned int col) {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += matrix[i][col];
    }

    return sum;
}

int calcFirstDiagonalSum(const int matrix[MAX_N][MAX_N], const unsigned int n) {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += matrix[i][i];
    }

    return sum;
}

int calcSecondDiagonalSum(const int matrix[MAX_N][MAX_N], const unsigned int n) {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += matrix[i][n - i - 1];
    }

    return sum;
}

bool isMagicSquare(const int matrix[MAX_N][MAX_N], const unsigned int n) {
    for (int i = 1; i < n; ++i) {
        if (calcRowSum(matrix, n, i) != calcRowSum(matrix, n, i - 1)) {
            return false;
        }

        if (calcColSum(matrix, n, i) != calcColSum(matrix, n, i - 1)) {
            return false;
        }
    }

    return calcFirstDiagonalSum(matrix, n) == calcSecondDiagonalSum(matrix, n);
}