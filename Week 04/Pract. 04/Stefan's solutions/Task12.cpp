#include <iostream>

using std::cin;
using std::cout;

const size_t MAX_SIZE = 50;

void readArray(int* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (int i = 0; i < rows; i++) {
        readArray(matrix[i], cols);
    }
}

int countOfNegatives(const int* arr, size_t size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

// Bonus: count by custom criteria //

int countByCriteria(const int* arr, size_t size, bool (*criteria)(int value)) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (criteria(arr[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    size_t rows, cols;
    cin >> rows >> cols;

    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, rows, cols);
    
    for (int i = 0; i < rows; i++) {
        cout << countOfNegatives(matrix[i], cols) << " ";
    }

    /*
    for (int i = 0; i < rows; i++) {
        cout << countByCriteria(matrix[i], cols, [](int value) { return value < 0; }) << " ";
    }
    */
}
