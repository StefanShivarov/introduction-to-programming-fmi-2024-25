#include <iostream>

using namespace std;

int main() {
    unsigned int n = 0, fibNum = 0;

    cout << "N: ";
    cin >> n;

    if (n == 1) {
        fibNum = 0;
    } else if (n == 2 || n == 3) {
        fibNum = 1;
    } else {
        unsigned int a = 0, b = 1, c = 1;
        
        for (int i = 4; i <= n; ++i) {
            a = b;
            b = c;
            c = a + b;
        }

        fibNum = c;
    }

    cout << "The " << n << "th Fibonacci number is: " << fibNum << endl;

    return 0;
}