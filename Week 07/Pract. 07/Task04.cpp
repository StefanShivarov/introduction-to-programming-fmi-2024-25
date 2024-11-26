#include <iostream>

char convertNumberToSymbol(size_t number);
void convertDecToKth(char *, size_t &, size_t, size_t);
bool checkPalindrome(char *, size_t);

int main()
{
	const size_t MAX_SIZE = 100;
	char symbols[MAX_SIZE];
	size_t decimalNum = 0;
	size_t symbolsLength = 0;
	size_t numeralSystem = 0;

	std::cout << "Number in decimal: ";
	std::cin >> decimalNum;
	std::cout << "Numberal system: ";
	std::cin >> numeralSystem;

	convertDecToKth(symbols, symbolsLength, decimalNum, numeralSystem);
	bool palindrome = checkPalindrome(symbols, symbolsLength);

	palindrome	?	std::cout << "true" : std::cout << "false";

	return 0;
}

bool checkPalindrome(char *arr, size_t arraySize)
{
	for (int i = 0, j = arraySize - 1; i < arraySize; ++i, j--)
	{
		if (arr[i] != arr[j])
		{
			return 0;
		}
	}

	return 1;
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

void convertDecToKth(char *array, size_t &resultSize, size_t number, size_t system)
{
	char symbol = ' ';

	while (1)
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
			break;
		}
	}
}