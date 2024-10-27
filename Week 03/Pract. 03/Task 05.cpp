#include <iostream>
#include <cmath>

using namespace std;

int countOfNumbers(long);

bool isPalindrome(long);

int main() {
	long number = 0;
	cout << "Enter a positive number: ";
	cin >> number;

	if (number < 0) {
		cout << "Error!";
	}
	else {
		if (isPalindrome(number)) {
			cout << "The number is a palindrome.";
		}
		else {
			cout << "The number is not a palindrome.";
		}
	}

	return 0;
}

int countOfNumbers(long num) {
	return (int)log10((long)num) + 1;
}

bool isPalindrome(long num) {
	int firstNum = 0, lastNum = 0;

	int numbersCount = countOfNumbers(num);

	for (int i = 0;numbersCount > 1;i++) {
		firstNum = num / pow(10, numbersCount - 1);
		lastNum = num % 10;

		if (firstNum == lastNum) {
			return true;
		}
		else {
			return false;
			break;
		}

		num %= (int)pow(10, numbersCount - 1);
		num /= 10;
		numbersCount -= 2;
	}
}


