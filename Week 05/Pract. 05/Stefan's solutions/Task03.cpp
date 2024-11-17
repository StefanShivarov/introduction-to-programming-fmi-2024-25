#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 50;

void readArray(int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

bool isSubarray(const int* sub, unsigned subSize, const int* arr, unsigned size) {
    if (subSize > size) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < subSize; j++) {
            if (sub[j] != arr[i + j]) {
                break;
            }

            if (j == subSize - 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    unsigned n;
    cin >> n;
    int arr[MAX_SIZE];
    readArray(arr, n);

    unsigned m;
    cin >> m;
    int sub[MAX_SIZE];
    readArray(sub, m);

    cout << isSubarray(sub, m, arr, n);
}