#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0, x = 0, res = 0;

    cout << "Numbers: ";
    cin >> a >> b >> x;

    if (x < a) {
        res = 1;
    } else if (x == a) {
        res = 2;
    } else if (x > a && x < b) {
        res = 3;
    } else if (x == b) {
        res = 4;
    } else if (x > b) {
        res = 5;
    }

    cout << "The result is: " << res << endl;

    return 0;
}