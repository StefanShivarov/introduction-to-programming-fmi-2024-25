#include <iostream>

using namespace std;

char symbolModifying(char);

int main() {
	char initialChar = '0';
	char symbol = initialChar;

	cout << "Enter a symbol: ";
	cin >> symbol;

	symbol = symbolModifying(symbol);

	cout << "Result: " << symbol;

	return 0;
}

char symbolModifying(char symbol) {
	int symbolInAscii = symbol;
	const int beginningOfLowerLettersInAscii = 97, endOfLowerLettersInAscii = 122;
	const int differenceBetweenLowerAndUpperLetterInAscii = 32;

	if (symbolInAscii >= beginningOfLowerLettersInAscii && symbolInAscii <= endOfLowerLettersInAscii) {
		return char(symbolInAscii - differenceBetweenLowerAndUpperLetterInAscii);
	}
	else {
		return symbol;
	}
}