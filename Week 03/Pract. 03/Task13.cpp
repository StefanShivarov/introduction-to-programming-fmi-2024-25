#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    } else {
        int counter = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                counter++;
            }
        }
        if (counter == 2) {
            return true;
        } else {
            return false;
        }
    }
}

void sumOfPrimes(int n) {
    int primeNum = 2, sum = 0;
    while (primeNum <= n) {
        if (isPrime(primeNum)) {
            sum += primeNum;
        }
        primeNum++;
    }
    cout << sum << endl;
}

int main() {
    int n;
    cin >> n;
    sumOfPrimes(n);
    return 0;
}
