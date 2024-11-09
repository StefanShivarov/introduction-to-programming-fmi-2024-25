#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

void printAbsValuesOfNeighbours(const int arr[], const unsigned int n);

int main() {
    int arr[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    printAbsValuesOfNeighbours(arr, n);

    return 0;
}

void printAbsValuesOfNeighbours(const int arr[], const unsigned int n) {
    for (int i = 1; i < n; ++i) {
        int diff = arr[i] - arr[i - 1];
        cout << (diff < 0 ? -diff : diff) << (i == n - 1 ? "\n" : " ");
    }
}