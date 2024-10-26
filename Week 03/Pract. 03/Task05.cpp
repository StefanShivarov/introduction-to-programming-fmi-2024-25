#include <iostream>

using namespace std;

bool isPalindrome(const unsigned int);

int main() {
    unsigned int num = 0;

    cout << "Enter a number: ";
    cin >> num;

    cout << (isPalindrome(num) ? "True" : "False") << endl;
}

bool isPalindrome(const unsigned int num) {
    unsigned int reversed = 0, numCopy = num;

    while (numCopy > 0) {
        reversed = reversed * 10 + numCopy % 10;
        numCopy /= 10;
    }

    return num == reversed;
}