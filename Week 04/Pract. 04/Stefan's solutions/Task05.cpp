#include <iostream>

using std::cin;
using std::cout;

void readArray(int* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool isMonotonicallyDecreasing(const int* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    size_t N;
    cin >> N;

    int arr[51];
    readArray(arr, N);
    if (isMonotonicallyDecreasing(arr, N)) {
        cout << "The series is monotonically decreasing.";
    }
    else {
        cout << "The series is not monotonically decreasing.";
    }
}
