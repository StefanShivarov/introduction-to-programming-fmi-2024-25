#include <iostream>

const size_t MAX_SIZE = 4;
const size_t MAX_STRING_SIZE = 40;
size_t *dynamicRead(size_t *array, const size_t SIZE, size_t &actualLength);
size_t *appendArray(size_t *array, const size_t ACTUAL_LENGTH, size_t &actualMaxLength);
char *modifyString(char *symbols, size_t *numbers, size_t &symbolsLength, const size_t NUMBERS_LENGTH, const char SYMBOL);
void shiftArray(char *array, const size_t ARRAY_LENGTH, const size_t START_POS);
void myStrcpy(char *source, char *dest);
size_t myStrlen(char *symbols);

int main()
{
	char symbols[MAX_STRING_SIZE];
	size_t numbers[MAX_SIZE];

	size_t symbolsLength = 0;
	size_t numbersLength = 0;
	
	std::cout << "Please enter your phrase: ";
	std::cin.getline(symbols, MAX_STRING_SIZE);

	symbolsLength = myStrlen(symbols);
	
	size_t *dynamicNumbers = dynamicRead(numbers, MAX_SIZE, numbersLength);

	char promptSymbol = ' ';

	std::cout << "Please write a sign to modify the string: ";
	std::cin >> promptSymbol;

	char *result = modifyString(symbols, dynamicNumbers, symbolsLength, numbersLength, promptSymbol);

	if (numbersLength > MAX_SIZE)
	{
		delete[] dynamicNumbers;
	}

	std::cout << result;

	delete[] result;

	return 0;
}

size_t *dynamicRead(size_t *array, const size_t SIZE, size_t &actualLength)
{
	if (array == nullptr)
	{
		return nullptr;
	}

	const size_t STOP = -9000;
	size_t maxLength = SIZE;
	size_t i = 0;
	size_t promptNumber = 0;
	size_t *temp = nullptr;
	bool madeDynamic = 0;

	std::cout << "Please enter number or numbers to create an array.\nTo stop the cycle enter a -9000 number:" << std::endl;

	while (1)
	{
		std::cin >> promptNumber;

		if (promptNumber == STOP)
		{
			std::cout << "Cycle stopped, " << promptNumber << " not added." << std::endl;
			return array;
		}

		if (i >= maxLength)
		{
			temp = array;
			array = appendArray(temp, actualLength, maxLength);

			if (madeDynamic)
			{
				delete[] temp;
			}

			madeDynamic = 1;
		}

		*(array + i) = promptNumber;

		actualLength++;
		i++;
	}
}

size_t *appendArray(size_t *array, const size_t ACTUAL_LENGTH, size_t &actualMaxLength)
{
	actualMaxLength = ACTUAL_LENGTH + 5;
	size_t *resultArray = new size_t[actualMaxLength];
	size_t i = 0;

	while (i < ACTUAL_LENGTH)
	{
		*(resultArray + i) = *(array + i);

		i++;
	}

	return resultArray;
}

char *modifyString(char *symbols, size_t *numbers, size_t &symbolsLength, const size_t NUMBERS_LENGTH, const char SYMBOL)
{
	const size_t resultLength = symbolsLength + NUMBERS_LENGTH + 1;
	char *result = new char[resultLength];
	*(result + resultLength) = '\0';

	myStrcpy(symbols, result);

	size_t i = 0;

	while(i < NUMBERS_LENGTH)
	{
		shiftArray(result, resultLength, *(numbers + i) + i);
		*(result + *(numbers + i) + i) = SYMBOL;

		i++;
	}

	return result;
}

void myStrcpy(char *source, char *dest)
{
	size_t i = 0;

	while(*(source + i))
	{
		*(dest + i) = *(source + i);
		i++;
	}

	*(dest + i) = '\0';
	i++;
}

void shiftArray(char *array, const size_t ARRAY_LENGTH, const size_t START_POS)
{
	if (array == nullptr || START_POS < 0 || START_POS > ARRAY_LENGTH)
	{
		return;
	}

	char *lowerBound = array + START_POS;
	const size_t HALF_BYTE = 4;
	const size_t SHIFT_SIZE = sizeof(short) * HALF_BYTE;

	char *upperBound = array + ARRAY_LENGTH - sizeof(short) - 1;

	short *scope = (short *)upperBound;

	while	(scope != (short *)(lowerBound - 1))
	{

		*scope <<= SHIFT_SIZE;
		scope = (short *)((char *)scope - 1);
	}
}

size_t myStrlen(char *symbols)
{
	size_t i = 0;
	while(*(symbols + i))
	{
		i++;
	}

	return i;
}