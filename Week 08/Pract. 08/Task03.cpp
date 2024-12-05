#include <iostream>

using namespace std;

void printArr(const int* arr, const size_t size);

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    printArr(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}

void printArr(const int* arr, const size_t size) {
    if (arr != nullptr) {
        for (int i = 0; i < size; ++i) {
            cout << *(arr + i) << (i == size - 1 ? "\n" : " ");
        }
    }
}