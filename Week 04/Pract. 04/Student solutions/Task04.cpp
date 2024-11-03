#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

double findAverage(const int arr[], const unsigned int n);

int main() {
    int arr[MAX_SIZE];
    unsigned int n = 0;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Average: " << findAverage(arr, n) << endl;

    return 0;
}

double findAverage(const int arr[], const unsigned int n) {
    double sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    return sum / n;
}