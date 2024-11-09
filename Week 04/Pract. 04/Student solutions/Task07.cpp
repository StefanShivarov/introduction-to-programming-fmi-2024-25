#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(char* arr, size_t size);
bool is_arr_symmetric(const char* arr, size_t size);

int main() {
    char arr[MAX_SIZE];

    size_t n;
    cin >> n;

    fill_arr(arr, n);

    if (is_arr_symmetric(arr, n)) cout << "Yes, the array is symmetric.";
    else cout << "No, the array is not symmetric.";

    return 0;
}

void fill_arr(char* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool is_arr_symmetric(const char* arr, const size_t size) {
    size_t back = size - 1;

    for (size_t front = 0; front < size / 2; front++) {
        if (arr[front] != arr[back--]) return false;
    }

    return true;
}