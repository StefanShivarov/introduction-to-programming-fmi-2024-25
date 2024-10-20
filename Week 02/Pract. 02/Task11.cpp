#include <iostream>

using namespace std;

int main() {
    unsigned int n = 0;

    cout << "N: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j % 2 == 0) {
                cout << j * n - i + 1 << " ";
            } else {
                cout << (j - 1) * n + i << " ";
            }
        }
        
        cout << endl;
    }
}