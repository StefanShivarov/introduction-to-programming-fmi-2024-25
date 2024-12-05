#include <iostream>

using namespace std;

int findIndexOfMaxElement(const int* arr, const size_t size);

int main() {
    size_t size;

    cout << "Enter the size: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        cin >> *(arr + i);
    }

    int maxElementIndex = findIndexOfMaxElement(arr, size);
    if (-1 != maxElementIndex) {
        cout << "Address of the max element: " << arr + maxElementIndex << endl;
    }

    delete[] arr;

    return 0;
}

int findIndexOfMaxElement(const int* arr, const size_t size) {
    if (arr == nullptr) {
        return -1;
    }

    int maxElementIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > *(arr + maxElementIndex)) {
            maxElementIndex = i;
        }
    }

    return maxElementIndex;
}