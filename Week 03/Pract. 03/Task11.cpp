#include <iostream>

using namespace std;

int sum_of_digits(long long num);

int main() {
    long long num;
    cin >> num;

    int sum = -1;

    while (sum < 0 || sum > 9) {
        sum = sum_of_digits(num);
        num = sum;
    }

    cout << sum_of_digits(num);

    return 0;
}

int sum_of_digits(long long num) {
    int sum = 0;

    while (num > 0) {
        sum += static_cast<int>(num % 10);
        num /= 10;
    }

    return sum;
}
