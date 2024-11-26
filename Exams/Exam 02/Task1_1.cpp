#include <iostream>
using namespace std;

const unsigned MAX_SIZE = 10;

bool isInsideInterval(int n, int min, int max) {
    return n >= min && n <= max;
}

double getAverage(const int arr[], unsigned size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return (double) sum / size;
}

int reversed(int num) {
    int result = 0;

    while (num) {
        result *= 10;
        result += num % 10;
        num /= 10;
    }

    return result;
}

bool isPalindrome(int num) {
    return reversed(num) == num;
}

int findClosestPalindrome(int num) {
    while (true) {
        if (isPalindrome(num)) {
            return num;
        }

        num--;
    }

    return 0;
}

int main() {
    int min, max;
    cin >> min >> max;
    
    if (min > max) {
        cout << "Invalid interval!";
        return -1;
    }

    unsigned n;
    cin >> n;

    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (!isInsideInterval(arr[i], min, max)) {
            cout << arr[i] << "is not in interval!";
            return -1;
        }
    }

    cout << getAverage(arr, n) << endl;

    for (int i = 0; i < n; i++) {
        cout << findClosestPalindrome(arr[i]) << " ";
    }
}
