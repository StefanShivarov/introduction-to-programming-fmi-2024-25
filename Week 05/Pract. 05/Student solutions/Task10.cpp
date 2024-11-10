#include <iostream>

using namespace std;

const size_t MAX_SIZE = 10;

void fill_arr(int arr[][MAX_SIZE], size_t size);
bool is_magic(const int arr[][MAX_SIZE], size_t size);
int row_sum(const int* arr, size_t columns);
int col_sum(const int arr[][MAX_SIZE], size_t col, size_t rows);
int main_diagonal_sum(const int arr[][MAX_SIZE], size_t size);
int secondary_diagonal_sum(const int arr[][MAX_SIZE], size_t size);

int main() {
    int arr[MAX_SIZE][MAX_SIZE];

    size_t size;
    cin >> size;

    fill_arr(arr, size);

    if (is_magic(arr, size)) cout << "magic";
    else cout << "not magic";

    return 0;
}

void fill_arr(int arr[][MAX_SIZE], const size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }
}

bool is_magic(const int arr[][MAX_SIZE], const size_t size) {
    int sum_row = 0, col_row = 0;

    for (size_t row = 0; row < size; row++) {
        const int curr_row_sum = row_sum(arr[row], size);
        if (sum_row != curr_row_sum && row != 0) return false;
        sum_row = curr_row_sum;
    }

    for (size_t col = 0; col < size; col++) {
        const int curr_col_sum = col_sum(arr, col, size);
        if (col_row != curr_col_sum && col != 0) return false;
        col_row = curr_col_sum;
    }

    if (main_diagonal_sum(arr, size) != secondary_diagonal_sum(arr, size)) return false;

    return true;
}

int row_sum(const int* arr, const size_t columns) {
    int sum = 0;

    for (size_t i = 0; i < columns; i++) {
        sum += arr[i];
    }

    return sum;
}

int col_sum(const int arr[][MAX_SIZE], const size_t col, const size_t rows) {
    int sum = 0;

    for (size_t i = 0; i < rows; i++) {
        sum += arr[i][col];
    }

    return sum;
}

int main_diagonal_sum(const int arr[][MAX_SIZE], const size_t size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += arr[i][i];
    }

    return sum;
}

int secondary_diagonal_sum(const int arr[][MAX_SIZE], const size_t size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += arr[i][size - i - 1];
    }

    return sum;
}