#include <iostream>

void findMinMax(const int* arr, int size, int& minValue, int& maxValue)
{
	minValue = arr[0];
	maxValue = arr[0];

	for (int increment = 0; increment < size; ++increment)
	{
		if (minValue > arr[increment])
		{
			minValue = arr[increment];
		}
		if (maxValue < arr[increment])
		{
			maxValue = arr[increment];
		}
	}
	std::cout << "Min: " << minValue << "\nMax: " << maxValue;
}

void main()
{
	const int ARRAY_SIZE = 5;
	int minimum = 0;
	int maximum = 0;

	int numbers[ARRAY_SIZE];
	for (int increment = 0; increment < ARRAY_SIZE; ++increment)
	{
		int insertingValue = 0;
		std::cin >> insertingValue;
		numbers[increment] = insertingValue;
	}

	findMinMax(numbers, ARRAY_SIZE, minimum, maximum);
}