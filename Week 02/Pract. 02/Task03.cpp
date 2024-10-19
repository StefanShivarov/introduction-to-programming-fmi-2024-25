#include <iostream>

using namespace std;

int main() {
    int num = 0;
    cin >> num;

    int factorial = 1;
    while (num) {
        factorial *= num--;
    }

    cout << factorial;

    return 0;
}
