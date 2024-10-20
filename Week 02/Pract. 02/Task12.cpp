#include <iostream>

using namespace std;

int main() {
    unsigned int n = 0;

    cout << "N: ";
    cin >> n;

    for (int i = 1; i < n + n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j <= i && j <= n + n - i) {
                cout << j << " ";
            } else {
                cout << "  ";
            }
        }

        for(int j = 0; j < n; ++j) {
            if (i == n) {
                cout << "-";
            } else {
                cout << " ";
            }
        }

        cout << " ";

        for(int j = n; j > 0; --j) {
            if (j <= i && j <= n + n - i) {
                cout << j << " ";
            } else {
                cout << "  ";
            }
        }
        
        cout << endl;
    }

    return 0;
}