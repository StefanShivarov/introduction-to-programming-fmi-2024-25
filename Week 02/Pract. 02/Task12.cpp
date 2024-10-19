#include <iostream>

using namespace std;

int main() {
    unsigned int n = 0;
    cin >> n;

    const unsigned int row_count = 2 * n - 1;
    const unsigned int char_per_row = 5 * n;

    int counter = 0;
    for (int row = 1; row <= row_count; row++) {
        if (row <= n) counter = row;
        else counter = 2 * n - row;

        for (int num = 1; num <= counter; num++) {
            cout << num << " ";
        }
        for (int symbol = 0; symbol < char_per_row - 4 * counter; symbol++) {
            char s = (row == n) ? '-' : ' ';
            cout << s;
        }
        cout << " ";
        for (int num = counter; num >= 1; num--) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}