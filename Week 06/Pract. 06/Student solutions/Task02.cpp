#include <iostream>

void fillSpiralArray(size_t (*array)[10], const size_t SIZE)
{
	int i, left = 0, top = 0, right = SIZE - 1, bottom = SIZE - 1;
	size_t increment = 0;

	while(left <= right && top <= bottom)
	{		
		for (i = left; i <= right; ++i)
		{
			++increment;
			array[top][i] = increment;
		}

		++top;

		for (i = top; i <= bottom; ++i)
		{
			++increment;
			array[i][right] = increment;
		}

		--right;
		
		if (top <= bottom) {
			for (i = right; i >= left; --i)
			{
				++increment;
				array[bottom][i] = increment;
			}

			--bottom;
		}

		if (left <= right) {
			for (i = bottom; i >= top; --i)
			{
				++increment;
				array[i][left] = increment;
			}

			++left;
		}
	}
}

void printArray(size_t (*array)[10], size_t MAX_SIZE)
{
	for (size_t i = 0; i < MAX_SIZE; ++i)
	{
		for (size_t j = 0; j < MAX_SIZE; ++j)
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
	size_t numbersQuantity = 0;
	std::cin >> numbersQuantity;

	fillSpiralArray(numbersData, numbersQuantity);
	printArray(numbersData, numbersQuantity);
}