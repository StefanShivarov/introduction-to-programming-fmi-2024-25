#include <iostream>

using namespace std;

bool isNumber(char);


int main()
{
	char initialSymbol = '0';
	char symbolFromConsole = initialSymbol;
	cout << "Enter a symbol: ";
	cin >> symbolFromConsole;

	if (isNumber(symbolFromConsole)) {
		cout << "Result: " << symbolFromConsole;
	}
	else {
		cout << "Result: -1";
	}

	return 0;
}

bool isNumber(char symbol) {
	int symbolInAscii = symbol;
	const int beginningOfNumbersInAscii = 48, endOfNumbersInAscii = 57;

	if (symbolInAscii >= beginningOfNumbersInAscii && symbolInAscii <= endOfNumbersInAscii) {
		return true;
	}
	else {
		return false;
	}
}