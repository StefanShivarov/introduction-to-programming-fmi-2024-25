#include <iostream>
using namespace std;

const size_t MAX_LENGTH = 100;

int* numsMultipliedByK(int arr1[], int arr2[], size_t length1, size_t length2,
    int K, size_t& resLength);

int main() {
    size_t length1 = 0, length2 = 0;
    cout << "Length of first array: ";
    cin >> length1;

    int* parr1 = new int[length1];
    cout << "Enter values of array: ";
    for (size_t i = 0; i < length1; i++) {
        cin >> parr1[i];
    }

    cout << "Length of second array: ";
    cin >> length2;

    int* parr2 = new int[length2];
    cout << "Enter values of array: ";
    for (size_t i = 0; i < length2; i++) {
        cin >> parr2[i];
    }

    int K = 0;
    cout << "Special num: ";
    cin >> K;

    size_t resLength = 0;
    int* presultArr = numsMultipliedByK(parr1, parr2, length1, length2, K, resLength);

    cout << "Result: ";
    for (size_t i = 0; i < resLength; i++) {
        cout << presultArr[i] << " ";
    }
    cout << endl;

    delete[] presultArr;

    delete[] parr1;
    delete[] parr2;

    return 0;
}

int* numsMultipliedByK(int arr1[], int arr2[], size_t length1, size_t length2,
    int K, size_t& resLength) {
    resLength = 0;

    if (length1 < length2) {
        for (size_t i = 0; i < length2; i++) {

            if (arr2[i] % K == 0) {
                for (size_t j = 0; j < length1; j++) {
                    if (arr2[i]==arr1[j]) {
                        resLength++;
                    }
                }
            }
        }
    }
    else {
        for (size_t i = 0; i < length1; i++) {

            if (arr1[i] % K == 0) {
                for (size_t j = 0; j < length2; j++) {
                    if (arr1[i] == arr2[j]) {
                        resLength++;
                    }
                }
            }
        }
    }

    int* presultArr = new int[resLength];

    int ind = 0;
    if (length1 < length2) {
        for (size_t i = 0; i < length2; i++) {

            if (arr2[i] % K == 0) {
                for (size_t j = 0; j < length1; j++) {
                    if (arr2[i] == arr1[j]) {
                        presultArr[ind] = arr2[i];
                        ind++;
                    }
                }
            }
        }
    }
    else {
        for (size_t i = 0; i < length1; i++) {

            if (arr1[i] % K == 0) {
                for (size_t j = 0; j < length2; j++) {
                    if (arr1[i] == arr2[j]) {
                        presultArr[ind] = arr1[i];
                        ind++;
                    }
                }
            }
        }
    }

    return presultArr;
}