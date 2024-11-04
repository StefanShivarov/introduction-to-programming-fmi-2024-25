#include <iostream>

using namespace std;

void findMinMax(const int* arr, int size, int& minValue, int& maxValue);

int main() {
    const int size = 5;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int minValue, maxValue;

    findMinMax(arr, size, minValue, maxValue);

    cout << "Min: " << minValue << endl;
    cout << "Max: " << maxValue << endl;

    return 0;
}

void findMinMax(const int* arr, int size, int& minValue, int& maxValue) {
    minValue = maxValue = arr[0];

    for (int i = 0; i < size; i++) {
        if (minValue > arr[i]) minValue = arr[i];
        if (maxValue < arr[i]) maxValue = arr[i];
    }
}