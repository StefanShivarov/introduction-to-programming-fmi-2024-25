#include <iostream>
#include <cmath>

using namespace std;

int getKDigit(const int, const int);
int reverseNumber(int);

int main() {
    int n = 0;
    unsigned int k = 0;

    cout << "Enter n and k: ";
    cin >> n >> k;

    cout << getKDigit(n, k) << endl;
}

int reverseNumber(int num) {
    int reversed = 0;

    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return reversed;
}

int getKDigit(const int n, const int k) {
    int reversed = reverseNumber(n);
    return (reversed / static_cast<int>(pow(10, k - 1))) % 10;
}