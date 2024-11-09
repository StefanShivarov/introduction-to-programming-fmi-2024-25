#include <iostream>

using std::cin;
using std::cout;

const size_t MAX_SIZE = 51;

void readArray(int* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void swap(int& a, int& b) {
    double temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 1; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binarySearch(const int* arr, int left, int right, int x)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    size_t N;
    cin >> N;

    int arr[MAX_SIZE];
    readArray(arr, N);
    bubbleSort(arr, N);

    cout << "x: ";
    int searchValue;
    cin >> searchValue;

    if (binarySearch(arr, 0, N, searchValue) != -1) {
        cout << "Yes, " << searchValue << " is in the array.";
    }
    else {
        cout << "No, " << searchValue << " is not in the array.";
    }
}
