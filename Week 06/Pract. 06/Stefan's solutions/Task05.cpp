#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 10;

void readMatrix(int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void spiralTraversal(const int matrix[][MAX_SIZE], unsigned rows, unsigned cols) {
    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;

    while (left <= right && top <= bottom) {
        /* Print the last column
        from the remaining columns */
        for (int i = bottom; i >= top; --i) {
            cout << matrix[i][right] << " ";
        }
        right--;

        /* Print the first row
        from the remaining rows */
        for (int i = right; i >= left; --i) {
            cout << matrix[top][i] << " ";
        }
        top++;

        /* Print the first column from
        the remaining columns */
        if (left <= right) {
            for (int i = top; i <= bottom; ++i) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }

        /* Print the last row from
        the remaining rows */
        if (top <= bottom) {
            for (int i = left; i <= right; ++i) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
    }
}

int main() {
    unsigned rows, cols;
    cin >> rows >> cols;

    int matrix[MAX_SIZE][MAX_SIZE];
    readMatrix(matrix, rows, cols);
    spiralTraversal(matrix, rows, cols);
}
