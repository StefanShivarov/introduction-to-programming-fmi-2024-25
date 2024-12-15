#include <iostream>
using namespace std;

int findBiggestSumOfDigits(int arr[], size_t N);

int sumOfDigits(int num);

int main() {
    size_t N = 0;
    cout << "Enter the number of values: ";
    cin >> N;

    int* parr = new int[N];
    cout << "Enter the values: ";
    for (size_t i = 0; i < N; i++) {
        cin >> parr[i];
    }

    const int DEFAULT_NOT_FOUND = -1;
    int S = findBiggestSumOfDigits(parr, N);
    int curSumOfDigits = 0;
    int found = false;

    for (size_t i = 0; i <= S; i++) {

        for (size_t j = 0; j < N; j++) {
            curSumOfDigits = sumOfDigits(parr[j]);

            if (curSumOfDigits == i) {
                cout << parr[j] << " ";
                found = true;
            }
        }

        if (found == false) {
            cout << DEFAULT_NOT_FOUND << " ";
        }

        found = false;
        cout << endl;
    }

    delete[] parr;

    return 0;
}

int sumOfDigits(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int findBiggestSumOfDigits(int arr[], size_t N) {
    int S = 0;
    int curSumOfDigits = 0;

    for (size_t i = 0; i < N; i++) {
        curSumOfDigits = sumOfDigits(arr[i]);

        if (curSumOfDigits > S) {
            S = curSumOfDigits;
        }
    }

    return S;
}