#include <iostream>

using namespace std;

int main() {
    unsigned int n = 0, factorial = 1;

    cout << "N: ";
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        factorial *= i;
    }

    cout << "Factorial: " << factorial << endl;

    return 0;
}