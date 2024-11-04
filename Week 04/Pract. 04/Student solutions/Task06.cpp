#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
bool series_decreasing_monotonically(const int* arr, size_t size);

int main() {
    int arr[MAX_SIZE];

    size_t n;
    cin >> n;

    fill_arr(arr, n);

    if (series_decreasing_monotonically(arr, n)) cout << "The series is monotonically decreasing.";
    else cout << "The series is not monotonically decreasing.";

    return 0;
}

void fill_arr(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool series_decreasing_monotonically(const int* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i + 1] > arr[i]) return false;
    }

    return true;
}