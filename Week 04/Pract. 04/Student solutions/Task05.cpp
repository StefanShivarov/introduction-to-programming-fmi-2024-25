#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, short size);
double average(const int* arr, short n);

int main() {
    int arr[MAX_SIZE];

    short n;
    cin >> n;

    fill_arr(arr, n);

    cout << "Average: " << average(arr, n);

    return 0;
}

void fill_arr(int* arr, short size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

double average(const int* arr, short n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / n;
}
