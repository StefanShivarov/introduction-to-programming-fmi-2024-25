#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
void print_arr_union(const int* arr1, const int* arr2, size_t size_1, size_t size_2);
bool element_in_array(const int* arr, size_t size, int element);

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];

    size_t size_1;
    cin >> size_1;

    fill_arr(arr1, size_1);

    size_t size_2;
    cin >> size_2;

    fill_arr(arr2, size_2);

    print_arr_union(arr1, arr2, size_1, size_2);

    return 0;
}

void fill_arr(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void print_arr_union(const int* arr1, const int* arr2, const size_t size_1, const size_t size_2) {
    for (size_t i = 0; i < size_1; i++) {
        cout << arr1[i] << " ";
    }

    for (size_t i = 0; i < size_2; i++) {
        if (!element_in_array(arr1, size_1, arr2[i]))
            cout << arr2[i] << " ";
    }
}

bool element_in_array(const int* arr, const size_t size, const int element) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == element) return true;
    }

    return false;
}