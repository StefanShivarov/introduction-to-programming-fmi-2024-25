#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 10;

void readMatrix(char matrix[][MAX_SIZE], unsigned n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool isPalindromicRow(const char matrix[][MAX_SIZE], unsigned n, unsigned rowIndex) {
    for (int i = 0; i < n / 2; i++) {
        if (matrix[rowIndex][i] != matrix[rowIndex][n - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isPalindromicCol(const char matrix[][MAX_SIZE], unsigned n, unsigned colIndex) {
    for (int i = 0; i < n / 2; i++) {
        if (matrix[i][colIndex] != matrix[n - i - 1][colIndex]) {
            return false;
        }
    }
    return true;
}

bool isPalindromicMainDiagonal(const char matrix[][MAX_SIZE], unsigned n) {
    for (int i = 0; i < n / 2; i++) {
        if (matrix[i][i] != matrix[n - i - 1][n - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isPalindromicSecondaryDiagonal(const char matrix[][MAX_SIZE], unsigned n) {
    for (int i = 0; i < n / 2; i++) {
        if (matrix[i][n - i - 1] != matrix[n - i - 1][i]) {
            return false;
        }
    }
    return true;
}

bool isPalindromicSquare(const char matrix[][MAX_SIZE], unsigned n) {
    if (!isPalindromicMainDiagonal(matrix, n) || !isPalindromicSecondaryDiagonal(matrix, n)) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        if (!isPalindromicRow(matrix, n, i) || !isPalindromicCol(matrix, n, i)) {
            return false;
        }
    }

    return true;
}

int main() {
    unsigned n;
    cin >> n;

    char matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, n);

    cout << (isPalindromicSquare(matrix, n) ? "palindrome square" : "not palindrome square");
}
