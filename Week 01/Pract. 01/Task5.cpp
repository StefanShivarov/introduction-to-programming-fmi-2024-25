#include <iostream>

using namespace std;

int main() {
    unsigned int num = 0;

    cout << "Number: "; cin >> num;

    unsigned int firstDigit = num / 1000;
    unsigned int secondDigit = (num / 100) % 10;
    unsigned int thirdDigit = (num / 10) % 10;
    unsigned int forthDigit = num % 10;

    unsigned int sum = firstDigit + secondDigit + thirdDigit + forthDigit;
    unsigned int p = firstDigit * secondDigit * thirdDigit * forthDigit;
    float avg = sum / 4.0;

    cout << "Sum = " << sum
        << "; P = " << p
        << "; Avg = " << avg << endl;

    return 0;
}