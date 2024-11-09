#include <iostream>

using std::cin;
using std::cout;

const size_t MAX_SIZE = 51;


void readArray(int* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

size_t countOfElement(const int* arr, size_t size, int element) {
    size_t count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

bool consistsOfDistinctOnly(const int* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        if (countOfElement(arr, size, arr[i]) > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    size_t N;
    cin >> N;

    int arr[MAX_SIZE];
    readArray(arr, N);

    if (consistsOfDistinctOnly(arr, N)) {
        cout << "Yes, the sequence consists of distinct elements.";
    }
    else {
        cout << "No, the sequence does not consist of distinct elements.";
    }
}
