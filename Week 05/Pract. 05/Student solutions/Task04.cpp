#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

void readArray(int arr[], const unsigned int n);
bool arePermutations(const int arr1[], const int arr2[], const unsigned int n);

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    readArray(arr1, n);
    readArray(arr2, n);

    cout << (arePermutations(arr1, arr2, n) ? "true" : "false") << endl;

    return 0;
}

void readArray(int arr[], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

bool arePermutations(const int arr1[], const int arr2[], const unsigned int n) {
    bool used[MAX_SIZE] = {false};

    for (int i = 0; i < n; ++i) {
        bool found = false;

        for (int j = 0; j < n; ++j) {
            if (!used[j] && arr1[j] == arr2[i]) {
                found = true;
                used[j] = true;
                break;
            }
        }

        if (!found) {
            return false;
        }
    }

    return true;
}