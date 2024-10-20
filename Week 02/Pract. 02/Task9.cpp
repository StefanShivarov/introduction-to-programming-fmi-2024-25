#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n = 0;
    char symbol;

    cout << "N: ";
    cin >> n;

    cout << "Symbol: ";
    cin >> symbol;
    

    for (int i = 1; i < n + n; ++i) {
        for (int j = 0; j < abs(n - i); ++j) {
            cout << " ";
        }

        for (int j = 0; j < n - abs(n - i) - 1; ++j) {
            cout << symbol;
        }

        cout << symbol;

        for (int j = 0; j < n - abs(n - i) - 1; ++j) {
            cout << symbol;
        }

        cout << endl;
    }

    return 0;
}