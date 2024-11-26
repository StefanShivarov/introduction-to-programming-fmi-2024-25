#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_matrix(int matrix[][MAX_SIZE], size_t size);
int diagonals_sum(const int matrix[][MAX_SIZE], size_t size);

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];

    size_t size;
    cin >> size;

    fill_matrix(matrix, size);

    cout << diagonals_sum(matrix, size);

    return 0;
}

void fill_matrix(int matrix[][MAX_SIZE], const size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

int diagonals_sum(const int matrix[][MAX_SIZE], const size_t size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += matrix[i][i] + matrix[i][size - i - 1];
    }

    if (size % 2 == 1) sum -= matrix[size / 2][size / 2];

    return sum;
}