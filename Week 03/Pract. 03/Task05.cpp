#include <iostream>
using namespace std;

void isPalindrome(int num) {
    int reversed = 0, orig = num;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num = num / 10;
    }
    if (reversed == orig) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

int main() {
    int num;
    cin >> num;
    isPalindrome(num);
    return 0;
}
