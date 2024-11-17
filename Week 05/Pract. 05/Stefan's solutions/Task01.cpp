#include <iostream>
using namespace std;

const unsigned MAX_SIZE = 50;

void readArray(int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

unsigned getMaxSequenceCountOfSameNumbers(const int* arr, unsigned size) {
    unsigned count = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        }
        else {
            count = 1;
        }
    }

    return count;
}

int main() {
    unsigned n;
    cin >> n;

    int arr[MAX_SIZE];
    readArray(arr, n);

    cout << getMaxSequenceCountOfSameNumbers(arr, n);
}