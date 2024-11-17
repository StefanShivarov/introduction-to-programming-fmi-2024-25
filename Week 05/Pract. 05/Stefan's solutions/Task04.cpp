#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 50;

void readArray(int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void copyArray(const int* source, int* dest, unsigned size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

bool areEqualArrays(const int* first, const int* second, unsigned size) {
    for (int i = 0; i < size; i++) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    return true;
}

bool arePermutations(const int* first, const int* second, unsigned size) {
    int sortedFirst[MAX_SIZE];
    int sortedSecond[MAX_SIZE];

    copyArray(first, sortedFirst, size);
    copyArray(second, sortedSecond, size);

    selectionSort(sortedFirst, size);
    selectionSort(sortedSecond, size);

    return areEqualArrays(sortedFirst, sortedSecond, size);
}

int main() {
    unsigned n;
    cin >> n;
    int first[MAX_SIZE];
    readArray(first, n);

    int second[MAX_SIZE];
    readArray(second, n);

    cout << arePermutations(first, second, n);
}