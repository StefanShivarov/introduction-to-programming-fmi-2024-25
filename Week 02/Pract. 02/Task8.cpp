#include <iostream>

using namespace std;

int main() {
    unsigned int n = 0;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }

        for (int j = 0; j < i; ++j) { 
            cout << "*";
        }

        cout << " | ";

        for (int j = 0; j < i; ++j) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}