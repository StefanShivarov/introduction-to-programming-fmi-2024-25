#include <iostream>
#include <cmath>

using namespace std;

int concat(const int, const int);

int main() {
    int first = 0, second = 0;

    cout << "Enter two numbers: ";
    cin >> first >> second;

    cout << concat(first, second) << endl;
}

int concat(const int first, const int second) {
    return first * pow(10, static_cast<int>(log10(second)) + 1) + second;
}
