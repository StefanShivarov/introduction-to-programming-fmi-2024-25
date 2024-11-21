#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_rectangle_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);
void print_spiral_anti_clockwise_matrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols);

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];

    size_t rows, cols;
    cin >> rows >> cols;

    fill_rectangle_matrix(matrix, rows, cols);

    print_spiral_anti_clockwise_matrix(matrix, rows, cols);

    return 0;
}

void fill_rectangle_matrix(int matrix[][MAX_SIZE], const size_t rows, const size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void print_spiral_anti_clockwise_matrix(const int matrix[][MAX_SIZE], const size_t rows, const size_t cols) {
    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;

    while (left <= right && top <= bottom) {
        for (int i = bottom; i >= top; i--) {
            cout << matrix[i][right] << " ";
        }
        right--;

        for (int i = right; i >= left; i--) {
            cout << matrix[top][i] << " ";
        }
        top++;

        for (size_t i = top; i <= bottom; i++) {
            cout << matrix[i][left] << " ";
        }
        left++;

        for (size_t i = left; i <= right; i++) {
            cout << matrix[bottom][i] << " ";
        }
        bottom--;
    }
}

