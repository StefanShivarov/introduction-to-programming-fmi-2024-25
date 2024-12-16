#include <iostream>
using namespace std;

const size_t MAX_LENGTH = 150;

bool isLetterOrNumber(char a);

char* findFirstWord(char str[]);

size_t myStrlen(char str[]);

void swap(char& a, char& b);

void reverseStr(char str[], size_t strLength);

char* findLastWord(char str[]);

char* firstAndLastWord(char firstWord[], char lastWord[]);

int main() {
	char str[MAX_LENGTH] = { '\0' };
	cout << "Enter a string: ";
	cin.getline(str, MAX_LENGTH);

	char* firstWord = findFirstWord(str);

	char* lastWord = findLastWord(str);

	char* concat = firstAndLastWord(firstWord, lastWord);
	cout << "Concat the first and the last word: " << concat << endl;

	delete[] concat;
	delete[] firstWord;
	delete[] lastWord;

	return 0;
}

bool isLetterOrNumber(char a) {
	bool isLowerCaseLetter = (a >= 'a' && a <= 'z');
	bool isUpperCaseLetter = (a >= 'A' && a <= 'Z');
	bool isNumber = (a >= '0' && a <= '9');

	return (isLowerCaseLetter || isUpperCaseLetter || isNumber);
}

char* findFirstWord(char str[]) {
	size_t wordLength = 0;

	bool found = false;
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (isLetterOrNumber(str[i])) {
			for (size_t j = i; str[j] != '\0'; j++) {

				if (isLetterOrNumber(str[j]))
					wordLength++;
				else
					break;
			}

			found = true;
		}

		if (found == true)
			break;
	}

	wordLength += 1;
	char* firstWord = new char[wordLength];
	
	int ind = 0;
	found = false;
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (isLetterOrNumber(str[i])) {
			for (size_t j = i; str[j] != '\0'; j++) {

				if (isLetterOrNumber(str[j])) {
					firstWord[ind] = str[j];
					ind++;
				}
				else
					break;
			}

			found = true;
		}

		if (found == true)
			break;
	}

	firstWord[ind] = '\0';

	return firstWord;
}

size_t myStrlen(char str[]) {
	size_t length = 0;

	for (size_t i = 0; str[i] != '\0'; i++) {
		length++;
	}

	return length;
}

void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

void reverseStr(char str[], size_t strLength) {
	for (int i = 0, j = strLength - 2; i < j; i++, j--) {
		swap(str[i], str[j]);
	}
}

char* findLastWord(char str[]) {
	size_t strLength = myStrlen(str);
	size_t wordLength = 0;

	bool found = false;
	for (int i = strLength - 1; i >= 0; i--) {
		if (isLetterOrNumber(str[i])) {
			for (int j = i; j >= 0; j--) {

				if (isLetterOrNumber(str[j]))
					wordLength++;
				else
					break;
			}

			found = true;
		}

		if (found == true)
			break;
	}

	wordLength += 1;
	char* lastWord = new char[wordLength];

	int ind = 0;
	found = false;
	for (int i = strLength - 1; i >= 0; i--) {
		if (isLetterOrNumber(str[i])) {
			for (int j = i; j >= 0; j--) {

				if (isLetterOrNumber(str[j])) {
					lastWord[ind] = str[j];
					ind++;
				}
				else
					break;
			}

			found = true;
		}

		if (found == true)
			break;
	}

	reverseStr(lastWord, wordLength);

	lastWord[ind] = '\0';

	return lastWord;
}

char* firstAndLastWord(char firstWord[], char lastWord[]) {
	size_t firstWordLength = myStrlen(firstWord);
	size_t lastWordLength = myStrlen(lastWord);

	size_t concatLength = firstWordLength + lastWordLength + 2;

	char* concat = new char[concatLength];
	
	int ind = 0;
	for (size_t i = 0; i < firstWordLength; i++) {
		concat[ind] = firstWord[i];
		ind++;
	}

	concat[ind] = ' ';
	ind++;

	for (size_t i = 0; i < lastWordLength; i++) {
		concat[ind] = lastWord[i];
		ind++;
	}

	concat[ind] = '\0';

	return concat;
}