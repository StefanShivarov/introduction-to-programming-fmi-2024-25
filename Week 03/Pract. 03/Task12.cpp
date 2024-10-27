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

int main() {
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << n << " is prime." << endl;
    } else {
        cout << n << " is not prime." << endl;
    }
    return 0;
}
