#include <iostream>
<<<<<<< Updated upstream

using namespace std;

int main() {
    int size = 0;
    cin >> size;

    for (int row = 0; row <= size; row++) {
        for (int left = 0; left < size; left++) {
            char symbol = (left < size - row) ? ' ' : '*';
            cout << symbol;
        }
        cout << " | ";
        for (int right = 0; right < size; right++) {
            char symbol = (right > row - 1) ? ' ' : '*';
            cout << symbol;
        }

=======
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = n - i; j >= 0; j--) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << " | ";
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
>>>>>>> Stashed changes
        cout << endl;
    }

    return 0;
<<<<<<< Updated upstream
}
=======
}
>>>>>>> Stashed changes
