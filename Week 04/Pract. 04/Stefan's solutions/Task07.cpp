#include <iostream>

using std::cin;
using std::cout;

const size_t MAX_SIZE = 51;

void readArray(char* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool isSymmetric(const char* arr, size_t size) {
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    size_t N;
    cin >> N;

    char arr[MAX_SIZE];
    readArray(arr, N);

    if (isSymmetric(arr, N)) {
        cout << "Yes, the array is symmetric.";
    }
    else {
        cout << "No, the array is not symmetric.";
    }
}
