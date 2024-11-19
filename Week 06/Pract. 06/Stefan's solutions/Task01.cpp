#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 10;

void readSquareMatrix(int matrix[][MAX_SIZE], unsigned n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

int getSumOfDiagonalsWithoutOverlap(const int matrix[][MAX_SIZE], unsigned n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
        sum += matrix[i][n - i - 1];
    }

    if (n % 2 != 0) {
        sum -= matrix[n / 2][n / 2];
    }

    return sum;
}

int main() {
    unsigned n;
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];
    readSquareMatrix(matrix, n);

    cout << getSumOfDiagonalsWithoutOverlap(matrix, n);
}
