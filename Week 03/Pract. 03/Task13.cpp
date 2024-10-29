#include <iostream>

using namespace std;

bool isPrime(const int);
unsigned int sumAllPrimesUntil(const int);

int main() {
    int num = 0;

    cout << "Enter a number: ";
    cin >> num;

    cout << sumAllPrimesUntil(num) << endl;
}

unsigned int sumAllPrimesUntil(const int num) {
    unsigned int sum = 0;

    for (int i = 2; i <= num; ++i) {
        if (isPrime(i)) {
            sum += i;
        }
    }
}