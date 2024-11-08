#include <iostream>

using std::cin;
using std::cout;

const size_t MAX_SIZE = 51;

void readArray(double* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

void bubbleSort(double* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 1; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(double* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void printArray(const double* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    size_t N;
    cin >> N;

    double arr[MAX_SIZE];
    readArray(arr, N);

    selectionSort(arr, N);
    // bubbleSort(arr, N);

    printArray(arr, N);
}
