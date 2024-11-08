#include <iostream>

using std::cin;
using std::cout;
using std::endl;

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

void printMatrix(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void squareEvenElementsInMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 == 0) {
                matrix[i][j] *= matrix[i][j];
            }
        }
    }
}

/* Bonus: modify matrix elements by custom condition and with custom action */

void modifyMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols,
                  bool (*condition)(int), void (*action)(int&)) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (condition(matrix[i][j])) {
                action(matrix[i][j]);
            }
        }
    }
}

int main() {
    size_t rows, cols;
    cin >> rows >> cols;

    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, rows, cols);

    squareEvenElementsInMatrix(matrix, rows, cols);

    // same thing but with custom condition and action:

    /*
    modifyMatrix(
        matrix, rows, cols,
        [](int element) { return element % 2 == 0; },
        [](int& element) { element *= element; }
    );
    */

    printMatrix(matrix, rows, cols);
}
