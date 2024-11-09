#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

unsigned int getLongestSequenceOfEqualElementsLen(const int arr[], const unsigned int n);

int main() {
    int arr[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << getLongestSequenceOfEqualElementsLen(arr, n) << endl;

    return 0;
}

unsigned int getLongestSequenceOfEqualElementsLen(const int arr[], const unsigned int n) {
    unsigned int maxLen = 1, count = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            ++count;
        } else {
            if (count > maxLen) {
                maxLen = count;
            }

            count = 1;
        }
    }

    if (count > maxLen) {
        maxLen = count;
    }

    return maxLen;
}