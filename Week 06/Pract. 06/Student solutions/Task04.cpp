#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_rectangle_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);
bool are_diagonals_ascending(const int matrix[][MAX_SIZE], size_t rows, size_t cols);

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];

    size_t rows, cols;
    cin >> rows >> cols;

    fill_rectangle_matrix(matrix, rows, cols);

    if (are_diagonals_ascending(matrix, rows, cols)) cout << "true";
    else cout << "false";

    return 0;
}

void fill_rectangle_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool are_diagonals_ascending(const int matrix[][MAX_SIZE], const size_t rows, const size_t cols) {
    for (size_t i = 1; i < rows; i++) {
        for (size_t j = 0; j < i; j++) {
            if (matrix[i - j][j] >= matrix[i - j - 1][j + 1]) return false;
        }
    }

    for (size_t i = 1; i < cols; i++) {
        for (int j = rows - 1; j > i; j--) {
            if (matrix[j][rows - j + i - 1] >= matrix[j - 1][rows - j + i]) return false;
        }
    }

    return true;
}
