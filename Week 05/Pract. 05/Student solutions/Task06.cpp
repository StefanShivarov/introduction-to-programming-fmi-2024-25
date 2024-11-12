#include <iostream>

using namespace std;

const size_t MAX_SIZE = 10, COLUMNS = 3;

void fill_arr(int arr[][COLUMNS], size_t rows, size_t columns);
void print_triangle_sides(const int arr[][COLUMNS], size_t rows, size_t columns);
void print_row(const int* arr, size_t columns);
bool are_triangle_sides(int a, int b, int c);

int main() {
    int arr[MAX_SIZE][COLUMNS];

    size_t rows;
    cin >> rows;

    fill_arr(arr, rows, COLUMNS);

    print_triangle_sides(arr, rows, COLUMNS);

    return 0;
}

void fill_arr(int arr[][COLUMNS], const size_t rows, const size_t columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            cin >> arr[i][j];
        }
    }
}

void print_triangle_sides(const int arr[][COLUMNS], const size_t rows, const size_t columns) {
    for (size_t i = 0; i < rows; i++) {
        if (are_triangle_sides(arr[i][0], arr[i][1], arr[i][2]))
            print_row(arr[i], columns);
    }
}

void print_row(const int* arr, const size_t columns) {
    for (size_t j = 0; j < columns; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;
}

bool are_triangle_sides(const int a, const int b, const int c) {
    return (a + b > c) && (b + c > a) && (a + c > b) && a > 0 && b > 0 && c > 0;
}