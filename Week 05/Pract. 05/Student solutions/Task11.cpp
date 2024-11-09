#include <iostream>

using namespace std;

const unsigned int MAX_N = 10;

void readMatrix(char matrix[MAX_N][MAX_N], const unsigned int n);
bool isRowPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n, const unsigned int row);
bool isColPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n, const unsigned int col);
bool isFirstDiagonalPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n);
bool isSecondDiagonalPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n);
bool isMagicPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n);

int main() {
    char matrix[MAX_N][MAX_N];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    readMatrix(matrix, n);

    cout << (isMagicPalindrome(matrix, n) ? "magic palindrome" : "not magic palindrome") << endl;

    return 0;
}

void readMatrix(char matrix[MAX_N][MAX_N], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
}

bool isRowPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n, const unsigned int row) {
    for (int i = 0; i < n / 2; ++i) {
        if (matrix[row][i] != matrix[row][n - i - 1]) {
            return false;
        }
    }

    return true;
}

bool isColPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n, const unsigned int col) {
    for (int i = 0; i < n / 2; ++i) {
        if (matrix[i][col] != matrix[n - i - 1][col]) {
            return false;
        }
    }

    return true;
}

bool isFirstDiagonalPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n) {
    for (int i = 0; i < n / 2; ++i) {
        if (matrix[i][i] != matrix[n - i - 1][n - i - 1]) {
            return false;
        }
    }

    return true;
}

bool isSecondDiagonalPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n) {
    for (int i = 0; i < n / 2; ++i) {
        if (matrix[i][n - i - 1] != matrix[n - i - 1][i]) {
            return false;
        }
    }

    return true;
}


bool isMagicPalindrome(const char matrix[MAX_N][MAX_N], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        if (!isRowPalindrome(matrix, n, i) || !isColPalindrome(matrix, n, i)) {
            return false;
        }
    }

    return isFirstDiagonalPalindrome(matrix, n) && isSecondDiagonalPalindrome(matrix, n);
}