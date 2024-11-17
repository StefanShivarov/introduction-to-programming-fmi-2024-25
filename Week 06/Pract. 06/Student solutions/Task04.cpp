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

bool isDescending(size_t (*array)[10], const size_t ROWS, const size_t COLS)
{
	size_t prevValue = 0;
	size_t prevDiagStart = 0;

	for (int i = COLS - 1; i >= 0; --i)
	{
		int row = ROWS - 1;
		int col = i;

		if (!prevDiagStart)
		{
			prevDiagStart = array[row][col];
		}
		else
		{
			if (array[row][col] <= prevDiagStart)
			{
				return 0;
			}
			prevDiagStart = array[row][col];
		}

		for (; row >= 0 && col < COLS; --row, ++col)
		{
			if (!prevValue)
			{
				prevValue = array[row][col];
				continue;
			}

			if(array[row][col] <= prevValue && array[row][col] != prevDiagStart)
			{
				return 0;
			}

			prevValue = array[row][col];
		}
	}

	for (int i = ROWS - 2; i >= 0; --i)
	{
		int row = i;
		int col = 0;

		if (array[row][col] <= prevDiagStart)
			{
				return 0;
			}
			prevDiagStart = array[row][col];

		for (; row >= 0 && col < COLS; --row, ++col)
		{
			if(array[row][col] <= prevValue && array[row][col] != prevDiagStart)
			{
				return 0;
			}

			prevValue = array[row][col];
		}
	}

	return 1;
}

void main()
{
	const size_t MAX_SIZE = 10;
	size_t numbersData[MAX_SIZE][MAX_SIZE];
	size_t numbersRows = 0;
	size_t numbersCols = 0;
	std::cin >> numbersRows >> numbersCols;

	fillArray(numbersData, numbersRows, numbersCols);
	bool descending = isDescending(numbersData, numbersRows, numbersCols);
	if(descending)
	{
		std::cout << "true";
	}
	else
	{
		std::cout << "false";
	}
}