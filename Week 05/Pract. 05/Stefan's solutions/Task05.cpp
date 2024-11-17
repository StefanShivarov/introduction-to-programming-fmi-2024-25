#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 50;
const double EPSILON = 1e-9;

void readArray(int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

double myAbs(double num) {
    return num < 0 ? -num : num;
}

bool isGreater(double a, double b) {
    return a - b > EPSILON;
}

double average(const int* arr, unsigned size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int getClosestToValue(const int* arr, unsigned size, double value) {
    int closest = arr[0];
    double minDiff = myAbs(value - closest);

    for (int i = 1; i < size; i++) {
        double currentDiff = myAbs(value - arr[i]);
        if (isGreater(minDiff, currentDiff)) {
            closest = arr[i];
            minDiff = currentDiff;
        }
    }
    return closest;
}

int main() {
    unsigned n;
    cin >> n;
    int arr[MAX_SIZE];
    readArray(arr, n);

    double avg = average(arr, n);
    cout << "Average: " << avg << endl;
    cout << "Closest: " << getClosestToValue(arr, n, avg);
}