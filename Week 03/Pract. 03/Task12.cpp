#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int main() {
    int n;
    cin >> n;

    if (isPrime(n)) cout << n << " is a prime number";
    else cout << n << " is not a prime number";

    return 0;
}

bool isPrime(const int n) {
    if (n < 2) return false;
    if (n == 2) return true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}