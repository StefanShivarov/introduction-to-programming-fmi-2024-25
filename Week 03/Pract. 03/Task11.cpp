#include <iostream>
using namespace std;

void sumOfDigits(long n) {
    if (n == 0) {
        cout << 0 << endl;
    } else {
        long sum = 0;
        while (n >= 10) {
            sum = 0;
            while (n != 0) {
                sum += n % 10;
                n /= 10;
            }
            n = sum; //108 //9
        }
        cout << sum << endl;
    }
}

int main() {
    long n; //999999999999
    cin >> n;
    sumOfDigits(n);
    return 0;
}
