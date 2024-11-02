#include <iostream>

void fillArray(int (*array)[4], const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			std::cin >> array[i][j];
		}
	}
}

int* amountNegatives(int (*array)[4], int* resultArray, const int MAX_SIZE)
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		for (int j = 0; j < MAX_SIZE; ++j)
		{
			if (array[i][j] < 0)
			{
				++resultArray[i];
			}
		}
	}

	return resultArray;
}

void printArray(int array[], int MAX_SIZE)
{
	for (int increment = 0; increment < MAX_SIZE; ++increment)
	{
		std::cout << array[increment] << " ";
	}
}

void main()
{
	const unsigned int MAX_SIZE = 4;
	int numbersData[MAX_SIZE][MAX_SIZE];
	int sumNegatives[MAX_SIZE] = {};

	fillArray(numbersData, MAX_SIZE);
	int* numbersNegatives = amountNegatives(numbersData, sumNegatives, MAX_SIZE);

	printArray(numbersNegatives, MAX_SIZE);

}