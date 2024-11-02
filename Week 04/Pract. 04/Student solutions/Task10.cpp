#include <iostream>

int* fillArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}

	return array;
}

int binarySearch(int arr[], int lowPos, int highPos, int x)
{
	while (lowPos <= highPos)
	{
		int midPos = lowPos + (highPos - lowPos) / 2;

		if (arr[midPos] == x)
		{
			return 1;
		}

		if (arr[midPos] < x)
		{
			lowPos = midPos + 1;
		}
		else
		{
			highPos = midPos - 1;
		}
	}

	return 0;
}

void main()
{
	int numbersQuantity = 0;
	const unsigned int MAX_SIZE = 15;
	int numbersEmpty[MAX_SIZE] = {};
	int element = 0;

	std::cin >> numbersQuantity;
	int* numbersData = fillArray(numbersEmpty, numbersQuantity);

	std::cout << "x: ";
	std::cin >> element;

	bool checkItem = binarySearch(numbersData, 0, numbersQuantity, element);

	if (checkItem)
	{
		std::cout << "Yes, " << element << " is in the array.";
	}
	else
	{
		std::cout << "No, " << element << " is not in the array.";
	}
}
