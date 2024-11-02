#include <iostream>

float* fillArray(float array[], const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}

	return array;
}

void printArray(float* array, const int SIZE) {
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << array[i] << " ";
	}
}

bool sortAscend(float array[], const int SIZE)
{
	for (int i = 0; i < SIZE - 1; ++i)
	{
		float minValue = array[i];

		for (int j = i + 1; j < SIZE; ++j)
		{
			if (array[j] < minValue)
			{
				minValue = array[j];
				float swap = array[i];
				array[i] = minValue;
				array[j] = swap;
			}
		}
	}

	return array;
}

void main()
{
	int numbersQuantity = 0;
	const unsigned int MAX_SIZE = 15;
	float numbersEmpty[MAX_SIZE] = {};

	std::cin >> numbersQuantity;
	float* numbersData = fillArray(numbersEmpty, numbersQuantity);

	float sortNums = sortAscend(numbersData, numbersQuantity);
	
	printArray(numbersData, numbersQuantity);
}
