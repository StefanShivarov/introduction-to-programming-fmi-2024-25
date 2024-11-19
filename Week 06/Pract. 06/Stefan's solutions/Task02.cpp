#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 10;

void spiralTraversalIncrement(int matrix[MAX_SIZE][MAX_SIZE], unsigned n) {
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int value = 1;

    while (left <= right && top <= bottom) {

        for (int i = left; i <= right; ++i) {
            matrix[top][i] = value++;
        }
        top++;

        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = value++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = value++;
            }
            left++;
        }
    }
}

void printSquareMatrix(const int matrix[][MAX_SIZE], unsigned n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned n;
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];
    spiralTraversalIncrement(matrix, n);

    printSquareMatrix(matrix, n);
}
