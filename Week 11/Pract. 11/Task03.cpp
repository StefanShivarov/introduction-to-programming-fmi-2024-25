#include <iostream>

const size_t MAX_SIZE = 4;
size_t *dynamicRead(size_t *array, const size_t SIZE, size_t &actualLength);
size_t *appendArray(size_t *array, const size_t ACTUAL_LENGTH, size_t &actualMaxLength);
void printArray(size_t *array, const size_t LENGTH);
size_t *findDivisibles(size_t *array, const size_t LENGTH, size_t &resultLength);
size_t divisiblesCount(size_t *array, size_t LENGTH);

int main()
{
	size_t numbers[MAX_SIZE];

	size_t arrayLength = 0;
	size_t resultLength = 0;

	size_t *dynamicArray = dynamicRead(numbers, MAX_SIZE, arrayLength);

	if (arrayLength < 2)
	{
		printArray(dynamicArray, arrayLength);
		return 1;
	}


	size_t *resultArray = findDivisibles(dynamicArray, arrayLength, resultLength);
	printArray(resultArray, resultLength);

	if (arrayLength >= MAX_SIZE)
	{
		delete[] dynamicArray;
	}

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

void printArray(size_t *array, const size_t LENGTH)
{
	size_t i = 0;

	while	(i < LENGTH)
	{
		std::cout << *(array + i) << " ";

		i++;
	}

	std::cout << std::endl;
}

size_t *findDivisibles(size_t *array, const size_t LENGTH, size_t &resultLength)
{
	resultLength = divisiblesCount(array, LENGTH);

	size_t *resultArray = new size_t[resultLength];
	size_t resultPosition = 0;
	bool divisable = 0;
	size_t i = 0;
	while(i < LENGTH)
	{
		divisable = 0;

		if( i > 0 && i < LENGTH - 1)
		{
			!(*(array + i) % *(array + i - 1)) ? divisable = 1 : 0;
			
			if (divisable)
			{
				*(resultArray + resultPosition) = *(array + i);
				resultPosition++;
				i++;
				continue;
			}

			!(*(array + i) % *(array + i + 1)) ? divisable = 1 : 0;
		}

		if (!i)
		{
			!(*(array + i) % *(array + i + 1)) ? divisable = 1 : 0;
		}

		if (i == LENGTH - 1)
		{
			!(*(array + i) % *(array + i - 1)) ? divisable = 1 : 0;
		}

		if (divisable)
			{
				*(resultArray + resultPosition) = *(array + i);
				resultPosition++;
			}

		i++;
	}

	return resultArray;
}

size_t divisiblesCount(size_t *array, size_t LENGTH)
{
	size_t i = 0;
	size_t count = 0;
	bool divisable = 0;

	while	(i < LENGTH)
	{
		divisable = 0;

		if( i > 0 && i < LENGTH - 1)
		{
			!(*(array + i) % *(array + i - 1)) ? divisable = 1 : 0;
			
			if (divisable)
			{
				count++;
				i++;
				continue;
			}

			!(*(array + i) % *(array + i + 1)) ? divisable = 1 : 0;
		}

		if (!i)
		{
			!(*(array + i) % *(array + i + 1)) ? divisable = 1 : 0;
		}

		if (i == LENGTH - 1)
		{
			!(*(array + i) % *(array + i - 1)) ? divisable = 1 : 0;
		}

		divisable ? count++ : 0;

		i++;
	}

	return count;
}