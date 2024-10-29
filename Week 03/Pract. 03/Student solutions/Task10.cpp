#include <iostream>

using namespace std;

const unsigned int HIGHEST_DIGIT = 9;

int sortDigits(const int);

int main() {
    int num = 0;

    cout << "Enter a number: ";
    cin >> num;

    cout << sortDigits(num) << endl;

    return 0;
}

int sortDigits(const int num) {
    int sortedNum = 0;

    for (int digit = 0; digit <= HIGHEST_DIGIT; ++digit) {
        for (int numCopy = num; numCopy > 0; numCopy /= 10) {
            if (numCopy % 10 == digit) {
                sortedNum = sortedNum * 10 + digit;
            }
        }   
    }

    return sortedNum;
}