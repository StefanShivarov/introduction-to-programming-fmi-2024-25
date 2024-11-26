#include <iostream>

void fillArray(char *, const size_t);
void printArray(char *, const size_t, bool);
size_t convertKthToDec(char *, const size_t, size_t);
size_t convertSymbolToNumber(char, size_t);
char convertNumberToSymbol(size_t number);
void convertDecToKth(char *, size_t &, size_t, size_t, size_t);

int main()
{
	const size_t MAX_SIZE = 100;
	char symbols[MAX_SIZE];
	char resultSymbols[MAX_SIZE];
	size_t inDecimal = 0;
	size_t symbolsLength = 0;
	size_t resultLength = 0;
	size_t numeralSystem = 0;

	std::cin >> symbolsLength >> numeralSystem;
	fillArray(symbols, symbolsLength);
	inDecimal = convertKthToDec(symbols, symbolsLength, numeralSystem);
	inDecimal++;
	convertDecToKth(resultSymbols, resultLength, inDecimal, numeralSystem, symbolsLength);
	printArray(resultSymbols, resultLength, 1);

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

void convertDecToKth(char *array, size_t &resultSize, size_t number, size_t system, size_t arraySize)
{
	char symbol = ' ';
	bool completed = 0;

	while (resultSize != arraySize || !completed)
	{
		if (number >= system)
		{
			if (number % system)
			{
				symbol = convertNumberToSymbol(number % system);
				array[resultSize] = symbol;
				number -= number % system;
				number /= system;
				++resultSize;
			}
			else
			{
				symbol = convertNumberToSymbol(0);
				array[resultSize] = symbol;
				number /= system;
				++resultSize;
			}
		}
		else
		{
			symbol = convertNumberToSymbol(number);
			array[resultSize] = symbol;
			number = 0;
			++resultSize;
			completed = 1;
		}
	}
}

void fillArray(char *array, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}
}

void printArray(char *array, const size_t SIZE, bool reverse = 0)
{
	if (reverse)
	{
		for (int i = SIZE-1; i >= 0; --i)
		{
			std::cout << array[i];
		}
	}
	else
	{
		for (size_t i = 0; i < SIZE; ++i)
		{
			std::cout << array[i];
		}
	}

	std::cout << std::endl;
}