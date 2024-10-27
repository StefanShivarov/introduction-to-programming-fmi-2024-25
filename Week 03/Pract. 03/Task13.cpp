#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);
long long primeSum(int n);

int main() {
    int n;
    cin >> n;

    cout << primeSum(n);

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

long long primeSum(const int n) {
    long long sum = 0;

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) sum += i;
    }

    return sum;
}