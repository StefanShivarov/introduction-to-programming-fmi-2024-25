#include <iostream>

void printArray(float* array, const int SIZE) {
	for (int increment = 0; increment < SIZE; ++increment)
	{
		std::cout << array[increment] << " ";
	}

	return;
}

bool sortAscend(const int SIZE)
{
	const unsigned int MAX_SIZE = 15;
	float numbers[MAX_SIZE] = {};

	for (int increment = 0; increment < SIZE; ++increment)
	{
		std::cin >> numbers[increment];
	}

	for (int outIncrement = 0; outIncrement < SIZE - 1; ++outIncrement)
	{
		float minValue = numbers[outIncrement];

		for (int inIncrement = outIncrement + 1; inIncrement < SIZE; ++inIncrement)
		{
			if (numbers[inIncrement] < minValue)
			{
				minValue = numbers[inIncrement];
				float swap = numbers[outIncrement];
				numbers[outIncrement] = minValue;
				numbers[inIncrement] = swap;
			}
		}
	}

	printArray(numbers, SIZE);

	return numbers;
}

void main()
{
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;
	float sortNums = sortAscend(numbersQuantity);
	
	return;
}
