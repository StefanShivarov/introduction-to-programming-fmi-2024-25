#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int);

int main() {
	int number = 0;
	cout << "Enter a number: ";
	cin >> number;

	if (number == 1) {
		cout << "The number is not prime.";
	}
	else if (isPrime(number)) {
		cout << "The number is prime.";
	}
	else {
		cout << "The number is not prime.";
	}

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
