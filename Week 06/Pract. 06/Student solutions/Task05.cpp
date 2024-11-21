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

void printSpiral(size_t (*array)[10], const size_t ROWS, const size_t COLS)
{
	int i, left = 0, top = 0, right = COLS - 1, bottom = ROWS - 1;

	while (left <= right && top <= bottom)
	{
		for (i = bottom; i >= top; --i)
		{
			std::cout << array[i][right] << " ";
		}
		--right;

		for (i = right; i >= left; --i)
		{
			std::cout << array[top][i] << " ";
		}
		++top;

		if (left <= right)
		{
			for (i = top; i <= bottom; ++i)
			{
				std::cout << array[i][left] << " ";
			}
			++left;
		}

		if (top <= bottom)
		{
			for (i = left; i <= right; ++i)
			{
				std::cout << array[bottom][i] << " ";
			}
			--bottom;
		}
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
	printSpiral(numbersData, numbersRows, numbersCols);
}