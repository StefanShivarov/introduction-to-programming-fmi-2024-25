#include <iostream>
#include <cmath>

using namespace std;

int digit_in_num(int n, int k);
int reverse_num(int num);

int main() {
    int n, k;
    cin >> n >> k;

    cout << digit_in_num(n, k);

    return 0;
}

int digit_in_num(int n, int k) {
    n = reverse_num(n);
    n /= static_cast<int>(pow(10, k - 1));
    return n % 10;
}

int reverse_num(int num) {
    int reverse = 0;

    for (int i = 0; num > 0; i++) {
        reverse = reverse * 10 + (num % 10);
        num /= 10;
    }

    return reverse;
}