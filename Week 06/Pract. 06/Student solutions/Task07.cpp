#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_rectangle_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);
void print_rectangle_matrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols);
void swap(int& a, int& b);
void sort_matrix(int matrix[][MAX_SIZE], size_t rows, size_t cols);

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];

    size_t rows, cols;
    cin >> rows >> cols;

    fill_rectangle_matrix(matrix, rows, cols);

    sort_matrix(matrix, rows, cols);

    print_rectangle_matrix(matrix, rows, cols);

    return 0;
}

void fill_rectangle_matrix(int matrix[][MAX_SIZE], const size_t rows, const size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void print_rectangle_matrix(const int matrix[][MAX_SIZE], const size_t rows, const size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void swap(int& a, int& b) {
    const int temp = a;
    a = b;
    b = temp;
}

void sort_matrix(int matrix[][MAX_SIZE], const size_t rows, const size_t cols) {
    int matrix_values[rows * cols];

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            matrix_values[(row * rows) + col] = matrix[row][col];
        }
    }

    for (size_t i = 0; i < rows * cols - 1; i++) {
        for (size_t j = 0; j < (rows * cols) - i - 1; j++) {
            if (matrix_values[j] > matrix_values[j + 1]) swap(matrix_values[j], matrix_values[j + 1]);
        }
    }

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            matrix[row][col] = matrix_values[(row * rows) + col];
        }
    }
}

