#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
void swap(int& a, int& b);
void bubble_sort(int* arr, size_t size);
bool are_arr_permutations(int* arr1, int* arr2, size_t size);

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];

    size_t size;
    cin >> size;

    fill_arr(arr1, size);
    fill_arr(arr2, size);

    if (are_arr_permutations(arr1, arr2, size)) cout << "true";
    else cout << "false";

    return 0;
}

void fill_arr(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void swap(int& a, int& b) {
    const int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int* arr, const size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

bool are_arr_permutations(int* arr1, int* arr2, const size_t size) {
    bubble_sort(arr1, size);
    bubble_sort(arr2, size);

    for (size_t i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) return false;
    }

    return true;
}