#include <iostream>
using namespace std;

const unsigned MAX_SIZE = 50;

void readArray(int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(const int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

unsigned myAbs(int num) {
    return num < 0 ? -num : num;
}

void extractAbsoluteDifferences(int* resultArr, const int* originalArr, unsigned size) {
    for (int i = 0; i < size - 1; i++) {
        resultArr[i] = myAbs(originalArr[i] - originalArr[i + 1]);
    }
}

int main() {
    unsigned n;
    cin >> n;

    int arr[MAX_SIZE];
    readArray(arr, n);

    int absoluteDiffs[MAX_SIZE];
    extractAbsoluteDifferences(absoluteDiffs, arr, n);

    printArray(absoluteDiffs, n - 1);
}