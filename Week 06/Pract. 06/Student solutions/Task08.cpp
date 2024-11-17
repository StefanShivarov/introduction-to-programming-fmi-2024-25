#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_rectangle_matrix(bool matrix[][MAX_SIZE], size_t rows, size_t cols);
int areas_in_matrix(const bool matrix[][MAX_SIZE], size_t rows, size_t cols);
void check_around(const bool matrix[][MAX_SIZE], bool checked[][MAX_SIZE], size_t rows, size_t cols, int row, int col);

int main() {
    bool matrix[MAX_SIZE][MAX_SIZE];

    size_t rows, cols;
    cin >> rows >> cols;

    fill_rectangle_matrix(matrix, rows, cols);

    cout << areas_in_matrix(matrix, rows, cols);

    return 0;
}

void fill_rectangle_matrix(bool matrix[][MAX_SIZE], const size_t rows, const size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

int areas_in_matrix(const bool matrix[][MAX_SIZE], const size_t rows, const size_t cols) {
    int areas = 0;
    bool checked[MAX_SIZE][MAX_SIZE] = {};

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (matrix[row][col] && !checked[row][col]) {
                check_around(matrix, checked, rows, cols, row, col);
                areas++;
            }
        }
    }

    return areas;
}

void check_around(const bool matrix[][MAX_SIZE], bool checked[][MAX_SIZE], const size_t rows, const size_t cols, const int row, const int col) {
    if (row < 0 || col < 0 || row >= rows || col >= cols || checked[row][col] || !matrix[row][col]) return;

    checked[row][col] = true;

    check_around(matrix, checked, rows, cols, row + 1, col);
    check_around(matrix, checked, rows, cols, row - 1, col);
    check_around(matrix, checked, rows, cols, row, col + 1);
    check_around(matrix, checked, rows, cols, row, col - 1);
}