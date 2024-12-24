#include <iostream>

const size_t MAX_SIZE = 4;
size_t *dynamicRead(size_t *array, const size_t SIZE, size_t &actualLength);
size_t *appendArray(size_t *array, const size_t ACTUAL_LENGTH, size_t &actualMaxLength);
void printArray(size_t *array, const size_t LENGTH);
void cycleArray(size_t *array, const size_t ARRAY_LENGTH, const size_t POSITIONS);

int main()
{
	size_t numbers[MAX_SIZE];

	size_t arrayLength = 0;
	size_t positions = 0;

	size_t *dynamicArray = dynamicRead(numbers, MAX_SIZE, arrayLength);

	if (arrayLength < 2)
	{
		printArray(dynamicArray, arrayLength);
		return 1;
	}

	std::cout << "Please enter the positions to cycle the array: ";
	std::cin >> positions;

	cycleArray(dynamicArray, arrayLength, positions);

	printArray(dynamicArray, arrayLength);

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
	if (array == nullptr)
	{
		return;
	}

	size_t i = 0;

	while	(i < LENGTH)
	{
		std::cout << *(array + i) << " ";

		i++;
	}

	std::cout << std::endl;
}

void cycleArray(size_t *array, const size_t ARRAY_LENGTH, const size_t POSITIONS)
{
	if (array == nullptr)
	{
		return;
	}

	size_t *lowerBound = array;
	const size_t HALF_BYTE = 4;
	const size_t LAST_POSITION = ARRAY_LENGTH - 1;
	const size_t HALF_SHIFT_SIZE = sizeof(size_t) * HALF_BYTE;

	size_t  *upperBound = lowerBound + LAST_POSITION;
	const size_t TIMES_CYCLE = 2;
	const size_t CYCLE_LIMIT = (ARRAY_LENGTH + ARRAY_LENGTH - TIMES_CYCLE) * TIMES_CYCLE;
	const size_t CYCLES = CYCLE_LIMIT * POSITIONS;

	size_t i = 0;
	size_t *scope = upperBound;
	size_t temp = *(array + LAST_POSITION);

	while	(i <= CYCLES)
	{		
		scope = (size_t *)((int *)scope - 1);

		*scope <<= HALF_SHIFT_SIZE;

		if (scope == lowerBound)
		{
			scope = upperBound;
			scope = (size_t *)((int *)scope + 1);
		}

		if(i && !(i % CYCLE_LIMIT))
		{
			scope = upperBound;
			*array = temp;
			temp = *(array + LAST_POSITION);
		}

		i++;
	}
}