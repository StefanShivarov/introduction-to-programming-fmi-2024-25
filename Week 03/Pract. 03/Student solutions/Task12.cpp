#include <iostream>

using namespace std;

bool isPrime(const int);

int main() {
    int num = 0;

    cout << "Enter a number: ";
    cin >> num;

    cout << (isPrime(num) ? "Prime" : "Not prime") << endl;

    return 0;
}

bool isPrime(const int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i < num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}