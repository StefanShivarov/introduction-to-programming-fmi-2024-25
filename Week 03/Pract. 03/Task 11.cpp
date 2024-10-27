#include <iostream>

using namespace std;

int sumOfNumbers(long long);

int modifyingIntoSingleDigitNumber(long long);

int main() {
	long long number = 0;
	cout << "Enter a number: ";
	cin >> number;
	
	cout << "Result: " << modifyingIntoSingleDigitNumber(number);

	return 0;
}

int sumOfNumbers(long long number) {
	int sum = 0;

	for (int k = 0; number > 0;k++) {
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

int modifyingIntoSingleDigitNumber(long long number) {
	for (int i = 0;number >= 10; i++) {
		number = sumOfNumbers(number);
	}

	return number;
}
