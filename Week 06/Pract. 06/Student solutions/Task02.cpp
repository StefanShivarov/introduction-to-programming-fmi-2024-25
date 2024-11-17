#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void print_matrix(const int matrix[][MAX_SIZE], size_t size);
void print_spiral_squared_matrix(size_t size);

int main() {
    size_t size;
    cin >> size;

    print_spiral_squared_matrix(size);

    return 0;
}

void print_matrix(const int matrix[][MAX_SIZE], const size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_spiral_squared_matrix(const size_t size) {
    int matrix[MAX_SIZE][MAX_SIZE];
    int value = 1, left = 0, right = size - 1, top = 0, bottom = size - 1;

    while (left <= right && top <= bottom) {
        for (size_t i = left; i <= right; i++) {
            matrix[top][i] = value++;
        }
        top++;

        for (size_t i = top; i <= bottom; i++) {
            matrix[i][right] = value++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = value++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = value++;
        }
        left++;
    }

    print_matrix(matrix, size);
}