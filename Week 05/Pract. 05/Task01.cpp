#include <iostream>

void fillArray(int* array, const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
			std::cin >> array[i];
	}
}

int findLongestRow(int* array, const int MAX_SIZE)
{
	int longestRow = 0;
	int prevLongestRow = 0;

	int checkValue = 0;
	checkValue = array[0];

	for (int i = 0; i < MAX_SIZE; ++i)
	{
		if (checkValue != array[i])
		{
			checkValue = array[i];
			if (prevLongestRow < longestRow)
			{
				prevLongestRow = longestRow;
			}
			longestRow = 0;
		}
		++longestRow;
	}

	if (longestRow < prevLongestRow)
	{
		return prevLongestRow;
	}
	return longestRow;
}

void main()
{
	const unsigned int MAX_SIZE = 15;
	int numbersData[MAX_SIZE];
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;

	fillArray(numbersData, numbersQuantity);
	int longestRow = findLongestRow(numbersData, numbersQuantity);

	std::cout << longestRow << std::endl;
}