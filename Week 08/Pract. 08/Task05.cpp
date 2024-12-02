#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

void largestAddress(int arr[], int n, int* &address) {
    for (int i = 1; i < n; i++) {
        if (arr[i] > *address) {
            address = &arr[i];
        }
    }
}

int main() {
    int arr[MAX_SIZE], num;
    cin >> num;

    if (num > MAX_SIZE) {
        return -1;
    }

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    int* address = &arr[0];
    largestAddress(arr, num, address);

    cout << address << '\n'; //<< *address;
}