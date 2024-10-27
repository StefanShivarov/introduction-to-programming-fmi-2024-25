#include <iostream>

using namespace std;

int ascii(char);

int main() {
	char symbol;
	cout << "Enter a symbol: ";
	cin >> symbol;

	cout << "Result: " << ascii(symbol);

	return 0;
}

int ascii(char symbol) {
	return (int)symbol;
}


