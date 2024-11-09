#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double average(const int* arr, size_t size) {
    double sum = 0.0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}


int main() {
    size_t N;
    cin >> N;

    int arr[51];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Average: " << average(arr, N);
}
