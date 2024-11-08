#include <iostream>

using std::cin;
using std::cout;

const size_t MAX_SIZE = 51;

void readArray(int* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool isZeroVector(const int* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            return false;
        }
    }
    return true;
}

bool areLinearlyDependent(const int* first, const int* second, size_t size) {
    if (isZeroVector(first, size) || isZeroVector(second, size)) {
        return true;
    }

    if (second[0] == 0) {
        return false;
    }

    double quotient = (double) first[0] / second[0];
    for (int i = 1; i < size; i++) {
        if (second[i] == 0 || (double) first[i] / second[i] != quotient) {
            return false;
        }
    }
    return true;
}

int main() {
    size_t N;
    cin >> N;

    int first[MAX_SIZE];
    int second[MAX_SIZE];
    readArray(first, N);
    readArray(second, N);

    if (areLinearlyDependent(first, second, N)) {
        cout << "Yes, the arrays are linearly dependent.";
    }
    else {
        cout << "No, the arrays are not linearly dependent.";
    }
}
