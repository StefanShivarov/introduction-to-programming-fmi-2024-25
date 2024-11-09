#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

void readArray(int arr[], const unsigned int n);
double findAvg(const int arr[], const unsigned int n);
int findClosestToAvg(const int arr[], const unsigned int n, const double avg);

int main() {
    int arr[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    readArray(arr, n);

    double avg = findAvg(arr, n);
    cout << "Average: " << avg << endl;

    int closest = findClosestToAvg(arr, n, avg);
    cout << "Closest to average: " << closest << endl;

    return 0;
}

void readArray(int arr[], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

double findAvg(const int arr[], const unsigned int n) {
    double sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    return sum / n;
}

int findClosestToAvg(const int arr[], const unsigned int n, const double avg) {
    int closest = arr[0];

    for (int i = 1; i < n; ++i) {
        if (abs(arr[i] - avg) < abs(closest - avg)) {
            closest = arr[i];
        }
    }

    return closest;
}