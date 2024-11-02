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

void powerEvenElements(int (*array)[4], const int MAX_SIZE)
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		for (int j = 0; j < MAX_SIZE; ++j)
		{
			if (!(array[i][j] % 2))
			{
				array[i][j] *= array[i][j];
			}
		}
	}
}

void printArray(int (*array)[4], int MAX_SIZE)
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		for (int j = 0; j < MAX_SIZE; ++j)
		{
			std::cout << array[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

void main()
{
	const unsigned int MAX_SIZE = 4;
	int numbersData[MAX_SIZE][MAX_SIZE];

	fillArray(numbersData, MAX_SIZE);
	powerEvenElements(numbersData, MAX_SIZE);

	printArray(numbersData, MAX_SIZE);
	
	return;
}