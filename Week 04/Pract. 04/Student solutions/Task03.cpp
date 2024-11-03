#include <iostream>

using namespace std;

const unsigned int ARRAY_SIZE = 5;

void findMinMax(const int* arr, int size, int& minValue, int& maxValue);

int main() {
    int arr[ARRAY_SIZE], minValue = 0, maxValue = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cin >> arr[i];
    }

    findMinMax(arr, ARRAY_SIZE, minValue, maxValue);

    cout << "Min: " << minValue << endl;
    cout << "Max: " << maxValue << endl;
}

void findMinMax(const int* arr, int size, int& minValue, int& maxValue) {
    minValue = maxValue = arr[0];

    for (int i = 0; i < size; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        } else if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
}