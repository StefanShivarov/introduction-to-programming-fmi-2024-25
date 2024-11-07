#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

bool isDistinct(const int arr[], const unsigned int n);

int main() {
    int arr[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (isDistinct(arr, n)) {
        cout << "Yes, the sequence consists of distinct elements." << endl;
    } else {
        cout << "No, the sequence does not consist of distinct elements." << endl;
    }

    return 0;
}

bool isDistinct(const int arr[], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }

    return true;
}