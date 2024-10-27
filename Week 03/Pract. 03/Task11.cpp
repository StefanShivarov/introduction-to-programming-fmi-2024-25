#include <iostream>

using namespace std;

const unsigned int HIGHEST_DIGIT = 9;

unsigned int sumDigits(int);
unsigned int sumDigitsUntilSingleDigit(const int);

int main() {
    int num = 0;

    cout << "Enter a number: ";
    cin >> num;

    cout << sumDigitsUntilSingleDigit(num) << endl;

    return 0;
}

unsigned int sumDigits(int num) {
    unsigned int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

unsigned int sumDigitsUntilSingleDigit(const int num) {
    unsigned int sum = sumDigits(num);

    while (sum > HIGHEST_DIGIT) {
        sum = sumDigits(sum);
    }

    return sum;
}