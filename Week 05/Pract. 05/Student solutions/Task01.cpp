#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
int repetition_length(const int* arr, size_t size);

int main() {
    int arr[MAX_SIZE];

    size_t size;
    cin >> size;

    fill_arr(arr, size);

    cout << repetition_length(arr, size);

    return 0;
}

void fill_arr(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int repetition_length(const int* arr, const size_t size) {
    int longest_length = 1, length = 1;

    for (size_t i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) length++;
        else {
            if (length >= longest_length) longest_length = length;
            length = 1;
        }
        cout << endl;
    }

    return (longest_length >= length) ? longest_length : length;
}