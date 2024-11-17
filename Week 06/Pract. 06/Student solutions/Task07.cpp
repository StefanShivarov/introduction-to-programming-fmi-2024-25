#include <iostream>

void fillArray(size_t (*array)[10], const size_t ROWS, const size_t COLS)
{
	for (size_t i = 0; i < ROWS; ++i)
	{
		for (size_t j = 0; j < COLS; ++j)
		{
			std::cin >> array[i][j];
		}
	}
}

void sortMatrix(size_t (*array)[10], const size_t ROWS, const size_t COLS)
{
	const size_t MAX_SIZE = ROWS * COLS;

	for (size_t i = 0, firstOutsideCounter = 0, secondOutsideCounter = 0; i < MAX_SIZE - 1; ++i, ++secondOutsideCounter)
	{
		if (secondOutsideCounter >= COLS)
		{
			++firstOutsideCounter;
			secondOutsideCounter = 0;
		}

		size_t minValue = array[firstOutsideCounter][secondOutsideCounter];

		for (size_t j = i + 1, firstInsideCounter = firstOutsideCounter, secondInsideCounter = secondOutsideCounter + 1; j < MAX_SIZE; ++j, ++secondInsideCounter)
		{
			if (secondInsideCounter >= COLS)
			{
				++firstInsideCounter;
				secondInsideCounter = 0;
			}

			if (array[firstInsideCounter][secondInsideCounter] < minValue)
			{
				minValue = array[firstInsideCounter][secondInsideCounter];
				size_t temp = array[firstOutsideCounter][secondOutsideCounter];
				array[firstOutsideCounter][secondOutsideCounter] = minValue;
				array[firstInsideCounter][secondInsideCounter] = temp;
			}
		}
	}
}

void printArray(size_t (*array)[10], const size_t ROWS, const size_t COLS)
{
	for (size_t i = 0; i < ROWS; ++i)
	{
		for (size_t j = 0; j < COLS; ++j)
		{
			std::cout << array[i][j] << " ";
		}

		std::cout << std::endl;
		}
}

void main()
{
	const size_t MAX_SIZE = 10;
	size_t numbersData[MAX_SIZE][MAX_SIZE];
	size_t numbersRows = 0;
	size_t numbersCols = 0;
	std::cin >> numbersRows >> numbersCols;

	fillArray(numbersData, numbersRows, numbersCols);
	sortMatrix(numbersData, numbersRows, numbersCols);
	printArray(numbersData, numbersRows, numbersCols);
}