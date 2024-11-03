#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

bool contains(const int arr[], const unsigned int n, const int x);

int main() {
    int arr[MAX_SIZE];
    unsigned int n;
    int x;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "X: ";
    cin >> x;

    if (contains(arr, n, x)) {
        cout << "Yes, " << x << " is in the array." << endl;
    } else {
        cout << "No, " << x << " is not in the array." << endl;
    }

    return 0;
}

bool contains(const int arr[], const unsigned int n, const int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            return true;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}