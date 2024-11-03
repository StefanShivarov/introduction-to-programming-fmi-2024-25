#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

void swap(double& a, double& b);
void sortArray(double arr[], const unsigned int n);

int main() {
    double arr[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sortArray(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "\n" : " ");
    }

    return 0;
}

void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

void sortArray(double arr[], const unsigned int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}