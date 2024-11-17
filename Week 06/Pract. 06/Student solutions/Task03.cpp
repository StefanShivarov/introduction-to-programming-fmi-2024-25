#include <iostream>

void fillArray(size_t (*array)[10], const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		for (size_t j = 0; j < SIZE; ++j)
		{
			std::cin >> array[i][j];
		}
	}
}

bool isSym(size_t (*array)[10], const size_t SIZE)
{
	size_t leftSide = 0;
	size_t rightSide = 0;
	for (size_t i = 0; i < SIZE; ++i)
	{
		for (size_t j = 0; j < SIZE; ++j)
		{
			if (j < i)
			{
				leftSide += array[i][j];
			}
			else if (j > i)
			{
				rightSide += array[i][j];
			}
		}
	}
	return leftSide == rightSide;
}

void main()
{
	const size_t MAX_SIZE = 10;
	size_t numbersData[MAX_SIZE][MAX_SIZE];
	size_t numbersQuantity = 0;
	std::cin >> numbersQuantity;

	fillArray(numbersData, numbersQuantity);
	bool sym = isSym(numbersData, numbersQuantity);
	if(sym)
	{
		std::cout << "true";
	}
	else
	{
		std::cout << "false";
	}
}