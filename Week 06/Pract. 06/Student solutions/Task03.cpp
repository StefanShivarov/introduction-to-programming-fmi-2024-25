#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_matrix(int matrix[][MAX_SIZE], size_t size);
bool is_matrix_symmetrical(const int matrix[][MAX_SIZE], size_t size);

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];

    size_t size;
    cin >> size;

    fill_matrix(matrix, size);

    if (is_matrix_symmetrical(matrix, size)) cout << "true";
    else cout << "false";

    return 0;
}

void fill_matrix(int matrix[][MAX_SIZE], const size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }
}

bool is_matrix_symmetrical(const int matrix[][MAX_SIZE], const size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (matrix[0][i] != matrix[i][0]) return false;
    }

    return true;
}
