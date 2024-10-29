#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

bool isPrime(int n) {
    int limit = sqrt(n); 
    for (int i = 2; i <= limit; i++) {  
        if (n % i == 0) {
            return false;
        }
    }

    return n >= 2;
}


int main() {
    int n;
    cin >> n;
    cout << isPrime(n);
}
