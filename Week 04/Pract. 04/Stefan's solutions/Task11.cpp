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

int sum(const int* arr, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    size_t rows, cols;
    cin >> rows >> cols;

    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, rows, cols);
    
    for (int i = 0; i < rows; i++) {
        cout << sum(matrix[i], cols) << " ";
    }
}
