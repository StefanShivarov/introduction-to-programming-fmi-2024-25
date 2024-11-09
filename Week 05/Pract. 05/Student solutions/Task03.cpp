#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
bool is_subarray(const int* arr_1, const int* arr_2, size_t size_1, size_t size_2);

int main() {
    int arr_1[MAX_SIZE], arr_2[MAX_SIZE];

    size_t size_1;
    cin >> size_1;

    fill_arr(arr_1, size_1);

    size_t size_2;
    cin >> size_2;

    fill_arr(arr_2, size_2);

    if (is_subarray(arr_1, arr_2, size_1, size_2)) cout << "true";
    else cout << "false";

    return 0;
}

void fill_arr(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool is_subarray(const int* arr_1, const int* arr_2, size_t size_1, size_t size_2) {
    for (size_t i = 0; i <= size_1 - size_2; i++) {
        bool found = true;

        for (size_t j = 0; j < size_2; j++) {
            if (arr_2[j] != arr_1[i + j]) {
                found = false;
                break;
            }
        }

        if (found) return true;
    }

    return false;
}