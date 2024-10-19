#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    for (int i = n; i >= 0; i--) {
        if (n >= pow(2, i)) {
            cout << "2^" << i;
            n -= static_cast<int>(pow(2, i));
            if (n > 0) cout << " + ";
        }
    }

    return 0;
}