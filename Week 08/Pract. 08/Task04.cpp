#include <iostream>

using namespace std;

bool isPalindrome(const int* arr, const size_t size, const int beg, const int end);
bool isConcatenationOfTwoPalindromes(const int* arr, const size_t size);

int main() {
    size_t size;

    cout << "Enter the size: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        cin >> *(arr + i);
    }

    cout << (isConcatenationOfTwoPalindromes(arr, size) ? "true" : "false") << endl;

    delete[] arr;

    return 0;
}

bool isPalindrome(const int* arr, const size_t size, const int beg, const int end) {
    if (arr == nullptr) {
        return false;
    }

    if (beg < 0 || end >= size) {
        return false;
    }

    for (int i = beg, j = end; i < j; ++i, --j) {
        if (*(arr + i) != *(arr + j)) {
            return false;
        }
    }

    return true;
}

bool isConcatenationOfTwoPalindromes(const int* arr, const size_t size) {
    if (arr == nullptr) {
        return false;
    }

    for (int i = size - 2; i >= 0; --i) {
        if (isPalindrome(arr, size, 0, i) && isPalindrome(arr, size, i + 1, size - 1)) {
            return true;
        }
    }

    return false;
}