#include <iostream>
using namespace std;

const size_t MAX_SIZE = 150;

size_t findNewStringLen(char str[]) {
	bool isExSpace = true;
	bool isCurSpace = true;

	int wordLen = 0;
	size_t newStrLen = 0;

	for (size_t i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			isCurSpace = false;
		}
		else {
			isCurSpace = true;
		}

		if (str[i] == ' ')
			newStrLen++;
		else
			wordLen++;

		if (isExSpace == true && isCurSpace == false) {
			newStrLen++;
		}
		else if (isExSpace == false && isCurSpace == true) {
			if (wordLen >= 2) {
				newStrLen += 2;
			}

			wordLen = 0;
		}

		if (str[i] != ' ') {
			isExSpace = false;
		}
		else {
			isExSpace = true;
		}
	}

	return newStrLen;
}

int myStrLen(char str[]) {
	int strLen = 0;
	for (size_t i = 0; str[i] != '\0'; i++) {
		strLen++;
	}

	return strLen;
}

char* modifyString(char str[]) {
	bool isExSpace = true;
	bool isCurSpace = true;

	int wordLen = 0;
	size_t newStrLen = findNewStringLen(str);

	char* newStr = new char[newStrLen + 1];
	int ind = 0;

	int stringLen = myStrLen(str);
	for (size_t i = 0; i <= stringLen; i++) {
		if (str[i] != ' ') {
			isCurSpace = false;
		}
		else {
			isCurSpace = true;
		}

		if (str[i] != ' ')
			wordLen++;

		if (isExSpace == true && isCurSpace == false) {
			newStr[ind] = str[i];
			ind++;
		}
		else if (isExSpace == false && isCurSpace == false) {
			wordLen++;
		}
		else if (isExSpace == false && isCurSpace == true) {
			if (wordLen >= 2) {
				newStr[ind] = str[i - 1];
				ind++;
			}

			wordLen = 0;
		}

		if (str[i] == ' ') {
			newStr[ind] = str[i];
			ind++;
		}

		if (str[i] != ' ') {
			isExSpace = false;
		}
		else {
			isExSpace = true;
		}
	}

	if (str[stringLen - 1] != ' ' && str[stringLen - 2] != ' ') {
		newStr[ind] = str[stringLen - 1];
		ind++;
	}

	newStr[ind] = '\0';

	return newStr;
}
int main() {
	char string[MAX_SIZE];
	cout << "Enter string: ";
	cin.getline(string, MAX_SIZE);

	char* outputStr = modifyString(string);
	cout << outputStr;

	delete[] outputStr;
	return 0;
}