#include <iostream>

const size_t MAX_SIZE = 150;

size_t mystrlen(char *symbols);
char *singles(char *symbols);
bool isInArray(char *symbols, char symbol, size_t startPos = 0);
size_t countSingles(char *symbols, const size_t LENGTH);

int main()
{
	char symbols[MAX_SIZE];

	std::cin >> symbols;

	size_t length = mystrlen(symbols);

	char *result = singles(symbols);

	if (!result)
	{
		return 1;
	}

	std::cout << result;

	delete[] result;

	return 0;
}

size_t mystrlen(char *symbols)
{
	size_t i = 0;

	while (*(symbols + i) )
	{
		i++;
	}

	return i;
}

size_t countSingles(char *symbols, const size_t LENGTH)
{
	char tempSymbols[MAX_SIZE];
	size_t tempPosition = 0;
	size_t result = 0;

	for (size_t i = 0; i < LENGTH; ++i)
	{
		char symbol = *(symbols + i);
		bool inTempArray = isInArray(tempSymbols, symbol);

		if (inTempArray)
		{
			continue;
		}
		else
		{
			*(tempSymbols + tempPosition) = symbol;
			tempPosition++;
			*(tempSymbols + tempPosition) = '\0';
			result++;
		}
	}

	return result;
}

bool isInArray(char *symbols, char symbol, size_t startPos)
{
	for (int i = startPos; *(symbols + i); ++i)
	{
		if (symbol == *(symbols + i))
		{
			return 1;
		}
	}

	return 0;
}

char *singles(char *symbols)
{
	size_t length = mystrlen(symbols);
	size_t singlesCount = countSingles(symbols, length);

	if (length < 1)
	{
		return nullptr;
	}

	size_t i = 0;
	size_t j = 0;

	char *newArray = new char[length + 1];
	size_t position = 0;

	for (size_t i = 0; i < length; ++i)
	{
		char symbol = *(symbols + i);
		bool inResult = isInArray(newArray, symbol);

		if (inResult)
		{
			continue;
		}
		else
		{
			*(newArray + position) = symbol;
			position++;
		}
	}

	*(newArray + length) = '\0';
	i++;

	return newArray;
}