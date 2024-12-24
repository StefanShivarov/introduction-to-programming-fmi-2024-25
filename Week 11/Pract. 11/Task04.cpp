#include <iostream>

const size_t MAX_SIZE = 4;
char *dynamicRead(char *array, const size_t SIZE, size_t &actualLength);
char *appendArray(char *array, const size_t ACTUAL_LENGTH, size_t &actualMaxLength);
char *concatCapital(char *firstArray, char *secondArray);
size_t countCapitals(char *symbols, bool upper = 0);

int main()
{
	char symbolsFirst[MAX_SIZE];
	char symbolsSecond[MAX_SIZE];

	size_t firstLength = 0;
	size_t secondLength = 0;

	char *dynamicFirst = dynamicRead(symbolsFirst, MAX_SIZE, firstLength);
	char *dynamicSecond = dynamicRead(symbolsSecond, MAX_SIZE, secondLength);

	char *result = concatCapital(dynamicFirst, dynamicSecond);

	if (firstLength > MAX_SIZE)
	{
		delete[] dynamicFirst;
	}

	if (secondLength > MAX_SIZE)
	{
		delete[] dynamicSecond;
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

char *concatCapital(char *firstArray, char *secondArray)
{
	size_t countLowers = countCapitals(firstArray);
	size_t countUppers = countCapitals(secondArray, 1);

	char *resultArray = new char[countLowers + countUppers + 1];

	size_t resultPosition = 0;
	size_t i = 0;

	while(*(firstArray + i))
	{
		if (*(firstArray + i) >= 'a' && *(firstArray + i) <= 'z')
		{
			*(resultArray + resultPosition) = *(firstArray + i);
			resultPosition++;
		}

		i++;
	}

	i = 0;

	while(*(secondArray + i))
	{
		if (*(secondArray + i) >= 'A' && *(secondArray + i) <= 'Z')
		{
			*(resultArray + resultPosition) = *(secondArray + i);
			resultPosition++;
		}

		i++;
	}

	*(resultArray + resultPosition) = '\0';
	resultPosition++;

	return resultArray;
}

size_t countCapitals(char *symbols, bool upper)
{
	size_t i = 0;
	size_t result = 0;

	while	(*(symbols + i))
	{
		if (upper)
		{
			if (*(symbols + i) >= 'a' && *(symbols + i) <= 'z')
			{
				result++;
			}
		}
		else
		{
			if (*(symbols + i) >= 'A' && *(symbols + i) <= 'Z')
			{
				result++;
			}
		}

		i++;
	}

return result;
}