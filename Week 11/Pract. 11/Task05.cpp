#include <iostream>

const size_t MAX_SIZE = 4;
char *dynamicRead(char *array, const size_t SIZE, size_t &actualLength);
char *appendArray(char *array, const size_t ACTUAL_LENGTH, size_t &actualMaxLength);
size_t countUniques(char *symbols, const size_t LENGTH);
bool isInArray(char *symbols, char symbol, const size_t SIZE, size_t startPos = 0);
char *uniques(char *symbols, size_t &symbolsLength);

int main()
{
	char symbols[MAX_SIZE];

	size_t symbolsLength = 0;

	char *dynamicSymbols = dynamicRead(symbols, MAX_SIZE, symbolsLength);

	char *result = uniques(dynamicSymbols, symbolsLength);

	if (symbolsLength > MAX_SIZE)
	{
		delete[] dynamicSymbols;
	}

	std::cout << result;

	delete[] result;

	return 0;
}

char *dynamicRead(char *array, const size_t SIZE, size_t &actualLength)
{
	if (array == nullptr)
	{
		return nullptr;
	}

	const char STOP = '!';
	size_t maxLength = SIZE;
	size_t i = 0;
	char promptSymbol = ' ';
	char *temp = nullptr;
	bool madeDynamic = 0;

	std::cout << "Please enter symbol or symbols to create an array.\nTo stop the cycle enter a ! symbol:" << std::endl;

	while (1)
	{
		std::cin >> promptSymbol;

		if (promptSymbol == STOP)
		{
			std::cout << "Cycle stopped, " << promptSymbol << " not added." << std::endl;
			return array;
		}

		if (i >= maxLength - 1)
		{
			temp = array;
			array = appendArray(temp, actualLength, maxLength);

			if (madeDynamic)
			{
				delete[] temp;
			}

			madeDynamic = 1;
		}

		*(array + i) = promptSymbol;

		actualLength++;
		i++;
	}

	*(array + i) = '\0';
	i++;
	actualLength++;
}

char *appendArray(char *array, const size_t ACTUAL_LENGTH, size_t &actualMaxLength)
{
	actualMaxLength = ACTUAL_LENGTH + 5;
	char *resultArray = new char[actualMaxLength];
	size_t i = 0;

	while (*(array + i))
	{
		*(resultArray + i) = *(array + i);

		i++;
	}

	return resultArray;
}

size_t countUniques(char *symbols, const size_t LENGTH)
{
	char *tempSymbols = new char[LENGTH];
	*(tempSymbols + LENGTH) = '\0';
	size_t tempPosition = 0;
	size_t result = 0;

	for (size_t i = 0; *(symbols + i); ++i)
	{
		char symbol = *(symbols + i);
		bool inTempArray = isInArray(tempSymbols, symbol, LENGTH);

		if (inTempArray)
		{
			continue;
		}
		else
		{
			bool inFurther = isInArray(symbols, symbol, LENGTH, i + 1);

			if (inFurther)
			{
				*(tempSymbols + tempPosition) = symbol;
				tempPosition++;
				*(tempSymbols + tempPosition) = '\0';
				continue;
			}

			result++;
		}
	}
	
	delete[] tempSymbols;

	return result;
}

bool isInArray(char *symbols, char symbol, const size_t SIZE, size_t startPos)
{
	if (startPos > SIZE)
	{
		return 0;
	}

	for (int i = startPos; *(symbols + i); ++i)
	{
		if (symbol == *(symbols + i))
		{
			return 1;
		}
	}

	return 0;
}

char *uniques(char *symbols, size_t &symbolsLength)
{
	size_t uniquesCount = countUniques(symbols, symbolsLength);

	if (symbolsLength < 1)
	{
		return nullptr;
	}

	size_t i = 0;
	size_t j = 0;

	char *result = new char[uniquesCount + 1];
	size_t position = 0;

	char *tempSymbols = new char[symbolsLength];
	*(tempSymbols + symbolsLength) = '\0';
	size_t tempPosition = 0;

	for (size_t i = 0; i < symbolsLength; ++i)
	{
		char symbol = *(symbols + i);
		bool inTemp = isInArray(tempSymbols, symbol, symbolsLength);

		if (inTemp)
		{
			continue;
		}
		else
		{
			bool inFurther = isInArray(symbols, symbol, symbolsLength, i + 1);

			if (inFurther)
			{
				*(tempSymbols + tempPosition) = symbol;
				tempPosition++;
				*(tempSymbols + tempPosition) = '\0';
				continue;
			}

			*(result + position) = symbol;
			position++;
		}
	}

	*(result + position) = '\0';
	position++;
	i++;

	delete[] tempSymbols;
	return result;
}