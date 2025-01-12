#include <iostream>
using namespace std;

const size_t MAX_SIZE = 150, ASCII_CODES = 128;

char* newStr(char str[]) {
	int outputStrLen = 0;
	int letCount[ASCII_CODES + 1];

	for (size_t i = 0; i <= ASCII_CODES; i++) {
		letCount[i] = 0;
	}

	for (size_t i = 0; str[i] != '\0'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			letCount[str[i]]++;
		}
	}

	for (size_t i = 0; i <= ASCII_CODES; i++) {
		outputStrLen += letCount[i];

		if (letCount[i] != 0) {
			outputStrLen += 5;
		}
	}

	outputStrLen--;
	char* newString = new char[outputStrLen];
	int ind = 0;
	for (size_t i = 0; str[i] != '\0'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			if (letCount[str[i]] != 0) {
				newString[ind] = str[i];
				ind++;
				newString[ind] = ':';
				ind++;
				newString[ind] = ' ';
				ind++;
				newString[ind] = letCount[str[i]] + '0';
				ind++;
				newString[ind] = ',';
				ind++;
				newString[ind] = ' ';
				ind++;
			}
		}

		letCount[str[i]] = 0;
	}

	ind-=2;
	newString[ind] = '\0';

	return newString;
}

int main() {
	char string[MAX_SIZE];
	cout << "Enter string: ";
	cin.getline(string, MAX_SIZE);

	char* outStr = newStr(string);
	cout << outStr;

	delete[] outStr;

	return 0;
}