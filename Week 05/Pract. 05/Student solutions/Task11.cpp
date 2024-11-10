#include <iostream>

using namespace std;

const size_t MAX_SIZE = 10;

void fill_arr(char arr[][MAX_SIZE], size_t size);
bool is_magic_palindrome(const char arr[][MAX_SIZE], size_t size);
bool is_palindrome(const char* arr, size_t size);

int main() {
    char arr[MAX_SIZE][MAX_SIZE];

    size_t size;
    cin >> size;

    fill_arr(arr, size);

    if (is_magic_palindrome(arr, size)) cout << "magic palindrome";
    else cout << "not magic palindrome";

    return 0;
}

void fill_arr(char arr[][MAX_SIZE], const size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }
}

bool is_magic_palindrome(const char arr[][MAX_SIZE], const size_t size) {
    for (size_t row = 0; row < size; row++) {
        if (!is_palindrome(arr[row], size)) return false;
    }

    char temp_arr[MAX_SIZE];

    for (size_t col = 0; col < size; col++) {
        for (size_t row = 0; row < size; row++) {
            temp_arr[row] = arr[row][col];
        }

        if (!is_palindrome(temp_arr, size)) return false;
    }

    for (size_t i = 0; i < size; i++) {
        temp_arr[i] = arr[i][i];
    }

    if (!is_palindrome(temp_arr, size)) return false;

    for (size_t i = 0; i < size; i++) {
        temp_arr[i] = arr[i][size - i - 1];
    }

    if (!is_palindrome(temp_arr, size)) return false;

    return true;
}

bool is_palindrome(const char* arr, const size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - i - 1]) return false;
    }

    return true;
}