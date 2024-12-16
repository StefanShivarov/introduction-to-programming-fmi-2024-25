#include <iostream>
using namespace std;

const size_t MAX_LENGTH = 150;
const int NUMBER_OF_ASCII_CODES = 128;
const int BEGGINING_OF_MEANINGFUL_SYMBOLS = 32;

char* elementsMetOnce(char str[]);

int main() {
	char str[MAX_LENGTH] = { '\0' };
	cout << "Enter a string: ";
	cin.getline(str, MAX_LENGTH);

	char* uniqueSymbols = elementsMetOnce(str);

	cout << "Symbols met once: " << uniqueSymbols << endl;

	delete[] uniqueSymbols;

	return 0;
}

char* elementsMetOnce(char str[]) {
	size_t resLength = 0;

	bool metOnce[NUMBER_OF_ASCII_CODES] = { 0 };
	for (size_t i = 0; i < NUMBER_OF_ASCII_CODES; i++) {
		metOnce[i] = 0;
	}

	bool metTwice[NUMBER_OF_ASCII_CODES] = { 0 };
	for (size_t i = 0; i < NUMBER_OF_ASCII_CODES; i++) {
		metTwice[i] = 0;
	}

	bool finalCheck[NUMBER_OF_ASCII_CODES] = { 0 };
	for (size_t i = 0; i < NUMBER_OF_ASCII_CODES; i++) {
		metTwice[i] = 0;
	}

	int code = BEGGINING_OF_MEANINGFUL_SYMBOLS;
	for (size_t i = 0; str[i] != '\0'; i++) {
		code = (int)str[i];

		if (metOnce[code] == 0) {
			metOnce[code] = 1;
		}
		else {
			metTwice[code] = 1;
		}
	}

	for (size_t i = BEGGINING_OF_MEANINGFUL_SYMBOLS; i < NUMBER_OF_ASCII_CODES; i++) {
		if (metOnce == 0) {
			continue;
		}

		if (!(metOnce[i] && metTwice[i])) {
			resLength++;
			finalCheck[i] = 1;
		}
	}

	char* uniqueSymbols = new char[resLength];

	int ind = 0;
	for (size_t i = 0; str[i] != '\0'; i++) {
		code = (int)str[i];

		if (finalCheck[code]) {
			uniqueSymbols[ind] = str[i];
			ind++;
		}
	}

	uniqueSymbols[ind] = '\0';

	return uniqueSymbols;
}