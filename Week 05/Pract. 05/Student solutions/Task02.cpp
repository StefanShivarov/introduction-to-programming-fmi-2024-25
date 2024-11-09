#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
void print_arr_abs_difference(const int* arr, size_t size);
int abs_difference(int a, int b);

int main() {
    int arr[MAX_SIZE];

    size_t size;
    cin >> size;

    fill_arr(arr, size);

    print_arr_abs_difference(arr, size);

    return 0;
}

void fill_arr(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void print_arr_abs_difference(const int* arr, const size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        cout << abs_difference(arr[i], arr[i + 1]) << " ";
    }
}

int abs_difference(const int a, const int b) {
    return (a >= b) ? a - b : b - a;
}