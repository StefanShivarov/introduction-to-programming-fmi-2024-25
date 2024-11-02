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

int* sumRows(int (*array)[4], int* resultArray, const int MAX_SIZE)
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		for (int j = 0; j < MAX_SIZE; ++j)
		{
			resultArray[i] += array[i][j];
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
	int sumEmpty[MAX_SIZE] = {};

	fillArray(numbersData, MAX_SIZE);
	int* numbersSum = sumRows(numbersData, sumEmpty, MAX_SIZE);

	printArray(numbersSum, MAX_SIZE);

}