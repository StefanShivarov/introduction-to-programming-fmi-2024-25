#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

void readArray(int arr[], const unsigned int n);
bool areLinearlyDependent(const int arr1[], const int arr2[], const unsigned int n);

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    readArray(arr1, n);
    readArray(arr2, n);

    if (areLinearlyDependent(arr1, arr2, n)) {
        cout << "Yes, the arrays are linearly dependent." << endl;
    } else {
        cout << "No, the arrays are not linearly dependent." << endl;
    }

    return 0;
}

void readArray(int arr[], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

bool areLinearlyDependent(const int arr1[], const int arr2[], const unsigned int n) {
    double k;
    bool isKInitialized = false; 
    
    for (int i = 0; i < n; ++i) {
        if (arr2[i] != 0) {
            if (!isKInitialized) {
                k = arr1[i] / ((double) arr2[i]);
                isKInitialized = true;
            } else {
                if (arr2[i] * k != arr1[i]) {
                    return false;
                }
            }
        } else if (arr1[i] != 0) {
            return false;
        }
    }

    return true;
}