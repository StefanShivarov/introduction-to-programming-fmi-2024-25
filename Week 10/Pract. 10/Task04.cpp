#include <iostream>

const size_t FIRST_LENGTH = 6;
const size_t SECOND_LENGTH = 7;

size_t *fraction(size_t *numbersFirst, const size_t FIRST_LENGTH, size_t *numbersSecond, const size_t SECOND_LENGTH, size_t denominator);
size_t divisables(size_t *numbersFirst, const size_t FIRST_LENGTH, size_t *numbersSecond, const size_t SECOND_LENGTH, size_t denominator);
bool isInSecond(size_t number, size_t *numbers, const size_t LENGTH);

int main()
{
	size_t numbersFirst[FIRST_LENGTH] = {1, 3, 6, 7, 8, 2};
	size_t numbersSecond[SECOND_LENGTH] = {2, 5, 7, 3, 9, 6, 11};
	size_t denominator = 0;

	std::cin >> denominator;

	size_t *result = fraction(numbersFirst, FIRST_LENGTH, numbersSecond, SECOND_LENGTH, denominator);

	delete[] result;

	return 0;
}

// void readArray(int *array, const size_t SIZE)
// {
// 	for (size_t i = 0; i < SIZE; ++i)
// 	{
// 		std::cin >> *(array + i);
// 	}
// }

// void readArray(int *array)
// {
// 	const int ERRORCODE = -4455;
//
//  // code to create dynamic array, check and copy to a new array.
//
// 	while (1)
// 	{
// 		std::cin >> number;

// 		if (number == ERRORCODE)
// 		{
// 			return;
// 		}

// 		*(array + i) = number;

// 		i++;
// 	}
// }

// size_t divisables(size_t *numbers, size_t length, size_t denominator)
// {
// 	size_t result = 0;

// 	for (size_t i = 0; i < length; ++i)
// 	{
// 		if (!(*(numbers + i) % denominator))
// 		{
// 			result++;
// 		}
// 	}

// 	return result;
// }

size_t divisables(size_t *numbersFirst, const size_t FIRST_LENGTH, size_t *numbersSecond, const size_t SECOND_LENGTH, size_t denominator)
{
	size_t result = 0;

	for (size_t i = 0; i < FIRST_LENGTH; ++i)
	{
		if (!(*(numbersFirst + i) % denominator))
		{
			bool inSecond = isInSecond(*(numbersFirst + i), numbersSecond, SECOND_LENGTH);

			if (inSecond)
			{
				result++;
			}
		}
	}

	return result;
}

bool isInSecond(size_t number, size_t *numbers, const size_t LENGTH)
{
	for (int i = 0; i < LENGTH; ++i)
	{
		if (number == *(numbers + i) )
		{
			return 1;
		}
	}

	return 0;
}

size_t *fraction(size_t *numbersFirst, const size_t FIRST_LENGTH, size_t *numbersSecond, const size_t SECOND_LENGTH, size_t denominator)
{
	size_t length = divisables(numbersFirst, FIRST_LENGTH, numbersSecond, SECOND_LENGTH, denominator);
	size_t position = 0;

	size_t *newArray = new size_t[length];

	for (size_t i = 0; i < FIRST_LENGTH; ++i)
	{
		if (!(*(numbersFirst + i) % denominator))
		{
			bool inSecond = isInSecond(*(numbersFirst + i), numbersSecond, SECOND_LENGTH);

			if (inSecond)
			{
				*(newArray + position) = *(numbersFirst + i);
				std::cout << *(newArray + position) << " ";
				position++;
			}
		}
	}

	return newArray;
}