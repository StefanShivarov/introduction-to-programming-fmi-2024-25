#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int);
int sumOfPrimeNumbers(int);

int main() {
	int limit = 0;
	cout << "Enter a number: ";
	cin >> limit;

	cout << "The sum of the prime numbers <" << limit << " is " << sumOfPrimeNumbers(limit);

	return 0;
}

bool isPrime(int n) {
	bool prime = true;

	for (int i = 2; i <= (int)sqrt(n);i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
		else {
			prime = true;
		}
	}

	return prime;
}

int sumOfPrimeNumbers(int limit) {
	int sum = 0;

	for (int i = 2;i < limit;i++) {
		if (isPrime(i)) {
			sum += i;
		}
	}

	return sum;
}
