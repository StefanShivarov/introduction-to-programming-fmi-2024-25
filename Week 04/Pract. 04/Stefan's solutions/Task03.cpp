#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void findMinMax(const int* arr, int size, int& minValue, int& maxValue) {
    minValue = arr[0];
    maxValue = arr[0];

    for (int i = 1; i < size; i++) {
        if (minValue > arr[i]) {
            minValue = arr[i];
        }
        if (maxValue < arr[i]) {
            maxValue = arr[i];
        }
    }
}

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int max, min;
    findMinMax(arr, 5, min, max);
    cout << "Min: " << min << endl << "Max: " << max;
}
