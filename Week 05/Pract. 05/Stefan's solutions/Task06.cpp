#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 50;

bool canFormTriangle(unsigned a, unsigned b, unsigned c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void printArray(const int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    unsigned rows;
    cin >> rows;
    int matrix[MAX_SIZE][3];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        if (canFormTriangle(matrix[i][0], matrix[i][1], matrix[i][2])) {
            printArray(matrix[i], 3);
            cout << endl;
        }
    }
}
