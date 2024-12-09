#include <iostream>

void fillArray(char *, const size_t);
size_t convertKthToDec(char *, const size_t, size_t);
size_t convertSymbolToNumber(char, size_t);
char convertNumberToSymbol(size_t number);

int main()
{
	const size_t MAX_SIZE = 100;
	char symbols[MAX_SIZE];
	char symbolsSecond[MAX_SIZE];
	size_t symbolsLength = 0;
	size_t symbolsSecondLength = 0;

	size_t numeralSystem = 0;
	size_t numeralSystemSecond = 0;

	size_t inDecimal = 0;
	size_t inDecimalSecond = 0;

	std::cin >> symbolsLength >> numeralSystem;
	fillArray(symbols, symbolsLength);
	std::cin >> symbolsSecondLength >> numeralSystemSecond;
	fillArray(symbolsSecond, symbolsSecondLength);

	inDecimal = convertKthToDec(symbols, symbolsLength, numeralSystem);
	inDecimalSecond = convertKthToDec(symbolsSecond, symbolsSecondLength, numeralSystemSecond);

	inDecimal == inDecimalSecond ? std::cout << "true" : std::cout << "false";

	return 0;
}

size_t convertSymbolToNumber(char symbol, size_t ERRCODE)
{
	size_t result = 0;

	if (symbol >= '0' && symbol <= '9')
	{
		return result = symbol - '0';
	}

	if (symbol >= 'A' && symbol <= 'Z')
	{
		return result = symbol - 'A' + 10;
	}

	if (symbol >= 'a' && symbol <= 'z')
	{
		return result = symbol - 'a' + 10;
	}

	return ERRCODE;
}

size_t convertKthToDec(char *array, const size_t SIZE, size_t system)
{
	size_t result = 0;
	size_t multiplier = 1;
	size_t convertedSymbol = 0;
	const size_t ERRCODE = 0xDDDD;

	for (int i = SIZE - 1; i >= 0; --i)
	{
		convertedSymbol = convertSymbolToNumber(array[i], ERRCODE);
		if (convertedSymbol == ERRCODE)
		{
			return ERRCODE;
		}

		result += convertedSymbol * multiplier;
		multiplier *= system;
	}

	return result;
}

char convertNumberToSymbol(size_t number)
{
	char symbol = ' ';

	if (number >= 0 && number <= 9)
	{
		return symbol = number + '0';
	}
	if (number > 9)
	{
		return symbol = number - 10 + 'A';
	}

	return symbol;
}

void fillArray(char *array, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}
}