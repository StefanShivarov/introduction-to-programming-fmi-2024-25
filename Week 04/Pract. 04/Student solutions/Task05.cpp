#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

bool isDecreasing(const int arr[], const unsigned int n);

int main() {
    int arr[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (isDecreasing(arr, n)) {
        cout << "The series is monotonically decreasing." << endl;
    } else {
        cout << "The series is not monotonically decreasing." << endl;
    }

    return 0;
}

bool isDecreasing(const int arr[], const unsigned int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }

    return true;
}