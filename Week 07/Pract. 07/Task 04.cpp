#include <iostream>

using namespace std;

const size_t  MIN_SIZE = 1, MAX_SIZE = 10;
const int MIN_K = 2, MAX_K = 16;

bool isInputDataValid(int K);

void printError();

int intToChar(int num);

void fromDecimalToK(char result[], long dec, int K, int& count);

bool isPalindrome(char result[], int length);

int main()
{
	unsigned int decimal = 0;
	cout << "Number in decimal: ";
	cin >> decimal;
	int K = 0;
	cout << "Enter K: ";
	cin >> K;

	if (isInputDataValid(K)) {
		char decToK[MAX_SIZE] = {};

		int count = 0;
		fromDecimalToK(decToK, decimal, K, count);

		if (isPalindrome(decToK, count)) {
			cout << "Palindrome.";
		}
		else {
			cout << "Not a palindrome.";
		}
	}
	else {
		printError();
	}

	return 0;
}

bool isInputDataValid(int K) {
	return (K >= MIN_K && K <= MAX_K);
}

void printError() {
	cout << "Error!";
}

int intToChar(int num) {
	if (num >= 0 && num <= 9) {
		return ((char)(num + '0'));
	}
	else if (num >= 10 && num <= 16) {
		return ((char)(num - 10 + 'A'));
	}
}

void fromDecimalToK(char result[], long dec, int K, int& count) {
	for (size_t i = 0; dec > 0; i++) {
		result[i] = intToChar(dec % K);
		dec /= K;

		count++;
	}
}

bool isPalindrome(char result[], int length) {
	for (size_t i = 0, j = length - 1;i < j; i++, j--) {
		if (result[i] != result[j]) {
			return false;
		}
	}
	return true;
}