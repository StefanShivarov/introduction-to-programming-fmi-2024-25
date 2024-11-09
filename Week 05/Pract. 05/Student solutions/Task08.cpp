#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

void readArray(int arr[], const unsigned int n);
void printIntersection(const int arr1[], const unsigned int n1, const int arr2[], const unsigned int n2);

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    unsigned int n1, n2;

    cout << "N1: ";
    cin >> n1;

    readArray(arr1, n1);

    cout << "N2: ";
    cin >> n2;

    readArray(arr2, n2);

    printIntersection(arr1, n1, arr2, n2);

    return 0;
}

void readArray(int arr[], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void printIntersection(const int arr1[], const unsigned int n1, const int arr2[], const unsigned int n2) {
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                break;
            }
        }
    }

    cout << endl;
}