#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
bool series_distinct(const int* arr, size_t size);

int main() {
    int arr[MAX_SIZE];

    size_t n;
    cin >> n;

    fill_arr(arr, n);

    if (series_distinct(arr, n)) cout << "Yes, the sequence consists of distinct elements.";
    else cout << "No, the sequence does not consist of distinct elements.";

    return 0;
}

void fill_arr(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool series_distinct(const int* arr, const size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) return false;
        }
    }

    return true;
}