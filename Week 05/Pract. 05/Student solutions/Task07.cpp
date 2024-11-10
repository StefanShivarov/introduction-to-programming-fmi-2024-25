#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
void print_arr(const int* arr, size_t size);
void swap(int& a, int& b);
void parity_bubble_sort(int* arr, size_t size);

int main() {
    int arr[MAX_SIZE];

    size_t size;
    cin >> size;

    fill_arr(arr, size);

    parity_bubble_sort(arr, size);

    print_arr(arr, size);

    return 0;
}

void fill_arr(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void print_arr(const int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void swap(int& a, int& b) {
    const int temp = a;
    a = b;
    b = temp;
}

void parity_bubble_sort(int* arr, const size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] % 2 > arr[j + 1] % 2) swap(arr[j], arr[j + 1]);
        }
    }
}