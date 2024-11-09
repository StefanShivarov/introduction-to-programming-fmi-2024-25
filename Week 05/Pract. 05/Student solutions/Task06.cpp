#include <iostream>

using namespace std;

const unsigned int MAX_ROWS = 10;
const unsigned int COLS = 3;

void readMatrix(int matrix[][COLS], const unsigned int rows);
bool areTriangleSides(const int a, const int b, const int c);

int main() {
    int matrix[MAX_ROWS][COLS];
    unsigned int rows;

    cout << "Rows: ";
    cin >> rows;

    readMatrix(matrix, rows);

    for (int i = 0; i < rows; ++i) {
        if (areTriangleSides(matrix[i][0], matrix[i][1], matrix[i][2])) {
            cout << matrix[i][0] << " " << matrix[i][1] << " " << matrix[i][2] << endl;
        }
    }

    return 0;
}

void readMatrix(int matrix[][COLS], const unsigned int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cin >> matrix[i][j];
        }
    }
}

bool areTriangleSides(const int a, const int b, const int c) {
    return a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a);
}