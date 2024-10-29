#include <iostream>

using namespace std;

bool is_palindrome(unsigned int num);
unsigned int reverse_num(unsigned int num);

int main() {
    unsigned int num;
    cin >> num;

    if (is_palindrome(num)) cout << "true";
    else cout << "false";

    return 0;
}

bool is_palindrome(const unsigned int num) {
    return num == reverse_num(num);
}

unsigned int reverse_num(unsigned int num) {
    unsigned int reverse = 0;

    for (int i = 0; num > 0; i++) {
        reverse = reverse * 10 + (num % 10);
        num /= 10;
    }

    return reverse;
}
