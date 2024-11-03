#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

bool isSymmetric(const char arr[], const unsigned int n);

int main() {
    char arr[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (isSymmetric(arr, n)) {
        cout << "Yes, the array is symmetric." << endl;
    } else {
        cout << "No, the array is not symmetric." << endl;
    }

    return 0;
}

bool isSymmetric(const char arr[], const unsigned int n) {
    for (int i = 0; i < n / 2; ++i) {
        if (arr[i] != arr[n - i - 1]) {
            return false;
        }
    }

    return true;
}