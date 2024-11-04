#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(double* arr, size_t size);
void bubble_sort(double* arr, size_t size);
void swap(int& a, int& b);
void print_arr(const double* arr, size_t size);

int main() {
    double arr[MAX_SIZE];

    size_t n;
    cin >> n;

    fill_arr(arr, n);

    bubble_sort(arr, n);

    print_arr(arr, n);

    return 0;
}

void fill_arr(double* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void bubble_sort(double* arr, const size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void swap(int& a, int& b) {
    const int temp = a;
    a = b;
    b = temp;
}

void print_arr(const double* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}