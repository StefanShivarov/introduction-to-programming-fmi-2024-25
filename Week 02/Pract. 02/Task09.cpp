#include <iostream>
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
using namespace std;

int main() {
    int n;
<<<<<<< Updated upstream
    char s;

    cin >> n >> s;

    int symbol_count = 1;

    for (int row = 0; row < n * 2 - 1; row++) {
        for (int space = 0; space < n - symbol_count / 2 - 1; space++) {
            cout << ' ';
        }

        for (int symbol = 0; symbol < symbol_count; symbol++) {
            cout << s;
        }

        if (row < n - 1) {
            symbol_count += 2;
        } else {
            symbol_count -= 2;
        }

=======
    cin >> n;
    char s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        for (int j = n - i; j >= 0; j--) {
            cout << " ";
        }
        for (int j = 0; j <= i * 2; j++) {
            cout << s;
        }
        cout << endl;
    }

    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= n - i; j++) {
            cout << " ";
        }
        for (int j = i * 2; j >= 0; j--) {
            cout << s;
        }
>>>>>>> Stashed changes
        cout << endl;
    }

    return 0;
}
