#include <iostream>

using namespace std;

int concat(int first, int second);

int main() {
    int first, second;
    cin >> first >> second;

    cout << concat(first, second);

    return 0;
}

int concat(int first, int second) {
    while (second) {
        first *= 10;
        second /= 10;
    }

    return first + second;
}
