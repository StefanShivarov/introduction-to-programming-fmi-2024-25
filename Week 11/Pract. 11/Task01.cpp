#include <iostream>

const size_t MAX_SIZE = 4;
size_t *dynamicRead(size_t *array, const size_t SIZE, size_t &actualLength);
size_t *appendArray(size_t *array, const size_t ACTUAL_LENGTH, size_t &actualMaxLength);
void printArray(size_t *array, const size_t LENGTH);
size_t *findNumerators(size_t *firstArray, size_t *secondArray, size_t firstLength, size_t secondLength, size_t &resultLength, const size_t DENOMINATOR);
size_t countNumerators(size_t *array, const size_t LENGTH, const size_t DENOMINATOR);

int main()
{
	size_t numbersFirst[MAX_SIZE];
	size_t numbersSecond[MAX_SIZE];

	size_t firstLength = 0;
	size_t secondLength = 0;
	size_t denominator = 0;

	size_t *dynamicFirst = dynamicRead(numbersFirst, MAX_SIZE, firstLength);
	size_t *dynamicSecond = dynamicRead(numbersSecond, MAX_SIZE, secondLength);

	std::cout << "Please write the denominator: ";

	std::cin >> denominator;

	size_t resultLength = 0;

	size_t *result = findNumerators(dynamicFirst, dynamicSecond, firstLength, secondLength, resultLength, denominator);

	std::cout << "All the numerators of " << denominator << " are: ";
	printArray(result, resultLength);

	if (firstLength > MAX_SIZE)
	{
		delete[] dynamicFirst;
	}

	if (secondLength > MAX_SIZE)
	{
		delete[] dynamicSecond;
	}

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

size_t *findNumerators(size_t *firstArray, size_t *secondArray, size_t firstLength, size_t secondLength, size_t &resultLength, const size_t DENOMINATOR)
{
	size_t firstNumerators = countNumerators(firstArray, firstLength, DENOMINATOR);
	size_t secondNumerators = countNumerators(secondArray, secondLength, DENOMINATOR);

	resultLength = firstNumerators + secondNumerators;
	size_t resultPosition = 0;

	size_t *resultArray = new size_t[resultLength];

	for (size_t i = 0; i < firstLength; ++i)
	{
		if (!(*(firstArray + i) % DENOMINATOR))
		{
			*(resultArray + resultPosition) = *(firstArray + i);
			resultPosition++;
		}
	}

	for (size_t i = 0; i < secondLength; ++i)
	{
		if (!(*(secondArray + i) % DENOMINATOR))
		{
			*(resultArray + resultPosition) = *(secondArray + i);
			resultPosition++;
		}
	}

	return resultArray;
}

size_t countNumerators(size_t *array, const size_t LENGTH, const size_t DENOMINATOR)
{
	size_t result = 0;

	for (size_t i = 0; i < LENGTH; ++i)
	{
		if (!(*(array + i) % DENOMINATOR))
		{
			result++;
		}
	}

	return result;
}