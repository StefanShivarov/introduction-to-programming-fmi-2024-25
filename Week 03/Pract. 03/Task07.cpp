#include <iostream>

int ascii(char symbol)
{
	int ascii_number = (int)symbol;

	return ascii_number;
}

int numerize(const char ASCII_SYMBOL)
{
	const int START_NUMBERS = 48;
	const int END_NUMBERS = 57;
	int get_symbol_number = ascii(ASCII_SYMBOL);
	int final_number = 0;

	if (get_symbol_number >= START_NUMBERS && get_symbol_number <= END_NUMBERS)
	{		
		final_number = get_symbol_number - START_NUMBERS;
		return (int)final_number;
	}
	else
	{
		return -1;
	}
}

int main()
{
	char ascii_symbol = ' ';

	std::cout << "Please enter a number: ";
	std::cin >> ascii_symbol;

	int get_number = numerize(ascii_symbol);

	std::cout << get_number;

	return 0;
}