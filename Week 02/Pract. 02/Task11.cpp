#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        for (int column = 0; column < n; column++) {
            if (column % 2 == 0) {
                cout << row + column * n << " ";
            } else {
                cout << (n - row + 1) + column * n << " ";
            }
        }
        cout << endl;
    }

    return 0;
}