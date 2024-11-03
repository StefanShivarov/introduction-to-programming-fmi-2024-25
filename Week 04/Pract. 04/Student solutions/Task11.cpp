#include <iostream>

using namespace std;

const unsigned int ROWS = 4;
const unsigned int COLS = 4;

int calcSum(const int arr[], const unsigned int n); 

int main() {
    int matrix[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        cout << calcSum(matrix[i], COLS) << (i == ROWS - 1 ? "\n" : " ");
    }

    return 0;
}

int calcSum(const int arr[], const unsigned int n) {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    return sum;
}