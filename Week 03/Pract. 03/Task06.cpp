#include <iostream>

int ascii(char symbol)
{
	int ascii_number = (int)symbol;

	return ascii_number;
}

char capitalize(const char ASCII_SYMBOL)
{
	const int START_ALPHABET = 97;
	const int END_ALPHABET = 122;
	const int POSITION_SHIFT = 32;
	int get_symbol_number = ascii(ASCII_SYMBOL);
	int capitalized_number = 0;

	if (get_symbol_number >= START_ALPHABET && get_symbol_number <= END_ALPHABET)
	{
		capitalized_number = get_symbol_number - POSITION_SHIFT;
		
		return (char)capitalized_number;
	}

	return ASCII_SYMBOL;
}

int main()
{
	char ascii_symbol = ' ';

	std::cout << "Please enter a letter you wish to capitalize: ";
	std::cin >> ascii_symbol;

	char get_capital_letter = capitalize(ascii_symbol);

	std::cout << get_capital_letter;

	return 0;
}