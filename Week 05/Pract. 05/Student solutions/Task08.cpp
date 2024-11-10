#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
void print_arr_intersection(const int* arr1, const int* arr2, size_t size_1, size_t size_2);

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];

    size_t size_1;
    cin >> size_1;

    fill_arr(arr1, size_1);

    size_t size_2;
    cin >> size_2;

    fill_arr(arr2, size_2);

    print_arr_intersection(arr1, arr2, size_1, size_2);

    return 0;
}

void fill_arr(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void print_arr_intersection(const int* arr1, const int* arr2, const size_t size_1, const size_t size_2) {
    bool used[MAX_SIZE] = {};

    for (size_t i = 0; i < size_1; i++) {
        for (size_t j = 0; j < size_2; j++) {
            if (arr1[i] == arr2[j] && !used[j]) {
                cout << arr1[i] << " ";
                used[j] = true;
            }
        }
    }
}