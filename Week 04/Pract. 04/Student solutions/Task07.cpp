#include <iostream>

int* fillArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}

	return array;
}

int timesSeen(int array[], const int SIZE, const int NUMBER)
{
	unsigned int seen = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		if (array[i] == NUMBER)
		{
			++seen;
		}
	}

	return seen;
}

bool isDistinctElem(int array[], const int SIZE)
{
	unsigned int amountPresent = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		amountPresent = timesSeen(array, SIZE, array[i]);

		if (amountPresent > 1)
		{
			return 0;
		}
	}
}

void main()
{
	int numbersQuantity = 0;
	const unsigned int MAX_SIZE = 15;
	int numbersEmpty[MAX_SIZE] = {};

	std::cin >> numbersQuantity;
	int* numbersData = fillArray(numbersEmpty, numbersQuantity);
	bool checkElements = isDistinctElem(numbersData, numbersQuantity);
	
	if (checkElements)
	{
		std::cout << "Yes, the sequence consists of distinct elements.";
	}
	else
	{
		std::cout << "No, the sequence does not consist of distinct elements.";
	}
}
