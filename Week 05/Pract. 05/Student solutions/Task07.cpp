#include <iostream>

using namespace std;

const unsigned int MAX_SIZE = 50;

void readArray(int arr[], const unsigned int n);
void printArray(const int arr[], const unsigned int n);
bool isEven(const int num);
bool isOdd(const int num);
void swap(int &a, int &b);
void sortElementsByParity(int arr[], const unsigned int n);

int main() {
    int arr[MAX_SIZE];
    unsigned int n;

    cout << "N: ";
    cin >> n;

    readArray(arr, n);
    sortElementsByParity(arr, n);
    printArray(arr, n);
    
    return 0;
}

void readArray(int arr[], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void printArray(const int arr[], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] <<(i == n - 1 ? "\n" : " ");
    }
}

bool isEven(const int num) {
    return num % 2 == 0;
}

bool isOdd(const int num) {
    return num % 2 != 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortElementsByParity(int arr[], const unsigned int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (isOdd(arr[j]) && isEven(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}