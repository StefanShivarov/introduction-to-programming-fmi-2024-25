#include <iostream>

int ascii(char symbol)
{
	int ascii_number = (int)symbol;

	return ascii_number;
}

int main()
{
	char ascii_symbol = ' ';

	std::cout << "Please enter an ascii symbol to get its integer number: ";
	std::cin >> ascii_symbol;

	std::cout << ascii(ascii_symbol) << std::endl;

	return 0;
}