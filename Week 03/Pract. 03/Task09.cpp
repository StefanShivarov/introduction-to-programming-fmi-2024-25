#include <iostream>

using namespace std;

int concat(int first, int second);

int main() {
    int first, second;
    cin >> first >> second;

    cout << concat(first, second);

    return 0;
}

int concat(int first, const int second) {
    int second_copy = second;
    while (second_copy) {
        first *= 10;
        second_copy /= 10;
    }

    return first + second;
}
