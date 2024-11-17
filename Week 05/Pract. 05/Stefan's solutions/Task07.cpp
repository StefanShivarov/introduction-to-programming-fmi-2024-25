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

void printArray(const int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

bool customComparator(int e1, int e2) {
    if ((e1 % 2 == 0) && (e2 % 2 != 0)) {
        // e1 is even and e2 is odd, e1 goes before e2
        return true;
    }

    if ((e1 % 2 != 0) && (e2 % 2 == 0)) {
        // e1 is odd and e2 is even, e2 goes before e1
        return false;
    }

    // if both are odd or both are even, the smaller one comes first
    return e1 < e2; 
}

void customSelectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (customComparator(arr[j], arr[minIndex])) {
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

int main() {
    unsigned n;
    cin >> n;

    int arr[MAX_SIZE];
    readArray(arr, n);

    customSelectionSort(arr, n);
    printArray(arr, n);
}
